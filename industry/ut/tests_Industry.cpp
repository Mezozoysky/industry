#include "HierarchyA.hpp"
#include <catch.hpp>
#include <industry/Industry.hpp>

using industry::Factory;
using industry::Industry;

using namespace ut;

TEST_CASE( "Basic Industry usage", "[Industry]" )
{
    Industry industry;

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

TEST_CASE( "Basic Industry usage 2", "[Industry]" )
{
    Industry industry;

    using FactoryA = Factory< BaseA >;
    using FactoryAPtr = std::shared_ptr< FactoryA >;

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
