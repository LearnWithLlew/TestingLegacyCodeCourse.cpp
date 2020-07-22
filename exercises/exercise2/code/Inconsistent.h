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
	int getID(time_t seed)
	{
		srand(seed);
		return (rand() % 10 + 1);
	}

    int getID()
    {
	    auto seed = time(0);
        return getID(seed);
    }

	//=================================

	int getID2(int rand1)
	{
		return (rand1 % 10 + 1);
	}

    int getID2()
    {
        srand(time(0));
        auto rand1 = rand();
        return getID2(rand1);
    }

	//=================================

	int getID3(std::function<int()> myRand)
	{
		srand(time(0));
		auto rand1 = myRand();
		int finalRand = 0;
		for(int i = 0; i < rand1 % 5; ++i)
		{
			finalRand += myRand();
		}
		return (finalRand % 10 + 1);
	}

    int getID3()
    {
        return getID3(rand);
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
