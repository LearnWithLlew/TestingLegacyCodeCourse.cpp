#ifndef TESTINGFUNCTIONALCODEKATA_LEGACY_H
#define TESTINGFUNCTIONALCODEKATA_LEGACY_H

#include <cstdlib>
#include <ctime>
#include <string>
#include <iostream>

class Legacy
{
    int count;

public:
    // Non-deterministic
    int getID()
    {
        srand(time(0));
        return (rand() % 10 + 1);
    }

    // Not all inputs passed in
    int getCategory()
    {
        if (count == 5)
        {
            return 2;
        }
        else
        {
            return 1;
        }
    }

    // Not all outputs passed out
    void printName(const std::string& name)
    {
        std::cout << name << '\n';
    }
};

#endif // TESTINGFUNCTIONALCODEKATA_LEGACY_H
