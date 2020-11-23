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

    int getID()
    {
        time_t current_time = time(0);
        time_t seed_for_random_number_generation = current_time;
        srand(seed_for_random_number_generation);
        int random_number = rand();
        return (random_number % 10 + 1);
    }

    std::string print(const std::string& name)
    {
        std::stringstream stream;
        std::chrono::system_clock::time_point end = std::chrono::system_clock::now();
        std::time_t end_time =
                std::chrono::system_clock::to_time_t(end);
        auto time = std::ctime(&end_time);
        time[strcspn(time, "\n")] = '\0';
        stream << "started at " << time << " by " << name;
        return stream.str();
    }
};
