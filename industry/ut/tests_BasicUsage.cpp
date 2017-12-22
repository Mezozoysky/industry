#include "HierarchyA.hpp"
#include <catch.hpp>
#include <industry/Industry.hpp>

using industry::Factory;
using industry::Industry;

using namespace ut;

using FactoryA = Factory< BaseA >;
using FactoryAPtr = std::shared_ptr< FactoryA >;


TEST_CASE( "Basic Factory usage with std::string ids", "[Factory]" )
{
    Factory< BaseA > factory;

    // static base creation
    {
        BaseA* objBaseA( Factory< BaseA >::create() );
        REQUIRE( objBaseA->getControlString() == "BaseA" );
        delete objBaseA;
        objBaseA = nullptr;
    }

    // "dynamic" base creation (using static create function from object)
    {
        BaseA* objBaseA( factory.create() );
        REQUIRE( objBaseA->getControlString() == "BaseA" );
        delete objBaseA;
        objBaseA = nullptr;
    }

    // static derived creation
    {
        DerivedA0A* objA0A{ Factory< BaseA >::create< DerivedA0A >() };
        DerivedA0B* objA0B{ Factory< BaseA >::create< DerivedA0B >() };
        REQUIRE( objA0A->getControlString() == "DerivedA0A" );
        REQUIRE( objA0B->getControlString() == "DerivedA0B" );
        delete objA0A;
        objA0A = nullptr;
        delete objA0B;
        objA0B = nullptr;
    }

    // "dynamic" derived creation (using static create<> function from object)
    {
        DerivedA0A* objA0A{ factory.create< DerivedA0A >() };
        DerivedA0B* objA0B{ factory.create< DerivedA0B >() };
        REQUIRE( objA0A->getControlString() == "DerivedA0A" );
        REQUIRE( objA0B->getControlString() == "DerivedA0B" );
        delete objA0A;
        objA0A = nullptr;
        delete objA0B;
        objA0B = nullptr;
    }

    factory.registerId< DerivedA0A >( "0A" );
    factory.registerId< DerivedA0B >( "0B" );

    // create derived by id
    {
        BaseA* objA0A = factory.create( "0A" );
        BaseA* objA0B = factory.create( "0B" );
        REQUIRE( objA0A->getControlString() == "DerivedA0A" );
        REQUIRE( objA0B->getControlString() == "DerivedA0B" );
        delete objA0A;
        objA0A = nullptr;
        delete objA0B;
        objA0B = nullptr;
    }

    // create base by id
    factory.registerId< BaseA >( "default" );
    {
        auto objBaseA( factory.create( "default" ) );
        REQUIRE( objBaseA->getControlString() == "BaseA" );
        delete objBaseA;
        objBaseA = nullptr;
    }
}

TEST_CASE( "Basic Industry usage with std::string ids", "[Industry]" )
{
    {
        Industry<> industry;

        {
            auto factoryA( industry.registerFactory< BaseA >() );
            REQUIRE( industry.hasFactory< BaseA >() );
            auto objA( factoryA->create() );
            REQUIRE( objA != nullptr );
            REQUIRE( objA->getControlString() == "BaseA" );
            delete objA;
            objA = nullptr;
        }

        {
            auto factoryA{ industry.registerFactory< BaseA >() };
            REQUIRE( factoryA == nullptr );
        }

        {
            auto factoryA{ industry.getFactory< BaseA >() };
            auto objA( factoryA->create() );
            REQUIRE( objA != nullptr );
            delete objA;
            objA = nullptr;
        }

        {
            auto objA( industry.getFactory< BaseA >()->create() );
            REQUIRE( objA != nullptr );
            delete objA;
            objA = nullptr;
        }
    }

    {
        Industry<> industry;

        {
            FactoryAPtr factory{ std::make_shared< FactoryA >() };
            bool registered{ industry.registerFactory( factory ) };
            REQUIRE( registered );
        }

        {
            FactoryAPtr factory{ std::make_shared< FactoryA >() };
            bool registered{ industry.registerFactory( factory ) };
            REQUIRE( !registered );
        }
    }
}

TEST_CASE( "Basic Industry usage with unsigned ids", "[Industry, Factory]" )
{
    {
        Industry< unsigned > industry;

        {
            auto factoryA( industry.registerFactory< BaseA >() );
            REQUIRE( industry.hasFactory< BaseA >() );
            auto objA( factoryA->create() );
            REQUIRE( objA != nullptr );
            REQUIRE( objA->getControlString() == "BaseA" );

            factoryA->registerId< DerivedA0A >( 1 );
            factoryA->registerId< DerivedA0B >( 2 );
        }

        {
            auto objA0A( industry.getFactory< BaseA >()->create( 1 ) );
            auto objA0B( industry.getFactory< BaseA >()->create( 2 ) );
            REQUIRE( objA0A->getControlString() == "DerivedA0A" );
            REQUIRE( objA0B->getControlString() == "DerivedA0B" );
            delete objA0A;
            objA0A = nullptr;
            delete objA0B;
            objA0B = nullptr;
        }
    }
}
