#pragma once
#include <cstdlib>
#include <ctime>
#include <string>
#include <iostream>
#include <sstream>
#include <ctime>
#include <chrono>

class Inconsistent
{
public:
    int getIDOriginal()
    {
        srand( time( 0 ) );
        return ( rand() % 10 + 1 );
    }

    int getID()
    {
        time_t current_time = time( 0 );
        time_t seed_for_random_number_generation = current_time;
        return getIDWithSeed( seed_for_random_number_generation );
    }
    int getIDWithSeed( time_t seed_for_random_number_generation ) const
    {
        srand( seed_for_random_number_generation );
        int random_number = rand();
        return getNumber( random_number );

    }
    int getNumber( int random_number ) const
    {
        auto const num = ( random_number % 10 + 1 );
        return num;
    }

    std::string print( const std::string& name )
    {
        std::chrono::system_clock::time_point end = std::chrono::system_clock::now();
        return printWithDate( name, end );
    }

    std::string printWithDate( const std::string& name,
                           const std::chrono::system_clock::time_point& end ) const
    {
        std::stringstream stream;
        time_t end_time = std::chrono::system_clock::to_time_t( end );
        auto time = ctime( &end_time );
        time[strcspn( time, "\n" )] = '\0';
        stream << "started at " << time << " by " << name;
        return stream.str();
    }
};
