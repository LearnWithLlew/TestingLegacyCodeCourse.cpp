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
	int get_id2(time_t seed)
	{
		srand(seed);
		return (rand() % 10 + 1);
	}

    int getID()
    {
        auto seed = time(0);
        return get_id2(seed);
    }

    std::string print2(const std::string& name, std::chrono::system_clock::time_point end)
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
        return print2(name, end);
    }
};
