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
    int getID()
    {
        srand(time(0));
        return (rand() % 10 + 1);
    }

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
