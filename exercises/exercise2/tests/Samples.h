#ifndef LEGACY_CODE_COURSE_SAMPLES_H
#define LEGACY_CODE_COURSE_SAMPLES_H

#include <catch2/catch.hpp>

#include <functional>

#include "ApprovalTests.hpp"

class SystemConfiguration
{
};

SystemConfiguration start( SystemConfiguration config )
{
    return config;
}

TEST_CASE( "Test Setup" )
{
    SystemConfiguration startingConfig;
    SystemConfiguration ending = start( startingConfig );
}

namespace Example1
{
    int getID()
    {
#ifdef TESTING
        srand( 500 );
#else
        srand( time( 0 ) );
#endif
        return ( rand() % 10 + 1 );
    }
}

namespace Example2
{
    int getID()
    {
        time_t seed = time( 0 );
        return getID( seed );
    }

    int getID( time_t seed )
    {
        srand( seed );
        return ( rand() % 10 + 1 );
    }
}

namespace Example3
{
    int getID()
    {
        srand( time( 0 ) );
        return getID( rand() );
    }

    int getID( int random )
    {
        return ( random % 10 + 1 );
    }
}

namespace Example4
{
    time_t& getRandomSeed()
    {
        static time_t randomSeed = time( 0 );
        return randomSeed;
    }

    int getID()
    {
        srand( getRandomSeed() );
        return ( rand() % 10 + 1 );
    }

    TEST_CASE( "Test with global seed in function" )
    {
        getRandomSeed() = 500;
        CHECK( getID() == 2 );
    }
}

namespace ScrubbingExample
{
    std::string scrub( const std::string& input )
    {
        return input;
    }

    void testRegexExample()
    {
        using namespace ApprovalTests;
        Approvals::verify( "text",
                           Options( ApprovalTests::Scrubbers::createRegexScrubber(
                               R"(\d+)", "[number]" ) ) );
    }
}

#endif //LEGACY_CODE_COURSE_SAMPLES_H
