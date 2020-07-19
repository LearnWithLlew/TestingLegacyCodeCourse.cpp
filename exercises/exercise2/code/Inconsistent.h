#pragma once
#include <cstdlib>
#include <ctime>
#include <string>
#include <iostream>
#include <sstream>
#include <ctime>
#include <chrono>

static time_t randomSeed = time(0);

time_t& randSeedStatic()
{
    static time_t randomSeed2 = time(0);
    return randomSeed2;
}

void setRandomSeed()
{
#ifdef TESTING
    srand(500);
#else
//    srand(time(0));
    srand(randSeedStatic());
#endif
}

class Inconsistent
{
    std::string name_;
public:
    Inconsistent(std::string name) : name_(name)
    {
        setRandomSeed();
    }

    int getID0()
    {
        return (rand() % 10 + 1);
    }
    // Non-deterministic
    int getID()
    {
        time_t seed = time(0);
        return getID(seed);
    }

    int getID(time_t seed) const {
        srand(seed);
        return (rand() % 10 + 1);
    }

    int getID2()
    {
//        time_t seed = time(0);
//        srand(seed);
        int randomNumber = rand();
        return getIdForRandom(randomNumber);
    }

    int getIdForRandom(int randomNumber) const { return (randomNumber % 10 + 1); }

    std::string print()
    {
        std::stringstream stream;
        auto end = std::chrono::system_clock::now();
        std::time_t end_time =
                std::chrono::system_clock::to_time_t(end);

        stream << "started at " << std::ctime(&end_time);
        return stream.str();
    }
};
