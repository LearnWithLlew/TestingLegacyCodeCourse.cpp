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

    std::string print1(const std::string& name)
    {
        auto end = std::chrono::system_clock::now();
        return print2(name, end);
    }

    std::string print2(const std::string &name, std::chrono::system_clock::time_point end) const {
        std::stringstream stream;
        time_t end_time =
                std::chrono::system_clock::to_time_t(end);
        auto time = std::ctime(&end_time);
        time[strcspn(time, "\n")] = '\0';
        stream << "started at " << time << " by " << name;
        return stream.str();
    }
};
