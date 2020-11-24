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
        srand(time(0));
        return (rand() % 10 + 1);
    }

    int getID2(int input)
    {
	    return (input % 10 + 1);
    }

    int getID(time_t current_time)
    {
	    time_t seed_for_random_number_generation = current_time;
	    srand(seed_for_random_number_generation);
	    int random_number = rand();
    
	    return getID2(random_number);
    }

    int getID()
    {
        time_t current_time = time(0);
        return getID(current_time);
    }

    std::string print(const std::string& name, std::chrono::system_clock::time_point end)
    {
	    std::stringstream stream;
	    std::time_t end_time =
		    std::chrono::system_clock::to_time_t(end);
	    auto time = std::ctime(&end_time);
	    time[strcspn(time, "\n")] = '\0';
	    stream << "started at " << time << " by " << name;
	    return stream.str();
    }

    std::string print(const std::string& name)
    {
	    return print(name, std::chrono::system_clock::now());
    }
};
