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
	int getID3(int i)
	{
		return (i % 10 + 1);
	}

	int getID2(int seed)
	{
        
		srand(seed);
        int i = rand();
		return getID3(i);
	}

    int getID()
    {
        int seed = 0;
#ifndef TESTING
        seed = time(0);
#endif
        return getID2(seed);
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
        std::chrono::system_clock::time_point end = std::chrono::system_clock::now();
    	return print(name, end);
    }
};
