#include <catch.hpp>
#include <industry/Factory.hpp>
#include "HierarchyA.hpp"

using industry::Factory;

using namespace ut;

TEST_CASE( "Basic Factory usage", "[Factory]" )
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
