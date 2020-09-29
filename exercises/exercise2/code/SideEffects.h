#pragma once

#include <cstdlib>
#include <ctime>
#include <string>
#include <iostream>

class SideEffects
{
public:
	std::string printName(const std::string& name)
	{
		std::stringstream name1;
		name1 << "Hello " << name << '\n';
		return name1.str();
	}

    // Not all outputs passed out
    void printName1(const std::string& name)
    {
         std::string output= printName(name);
        std::cout << output;
    }

	void printName22(const std::string& name, std::ostream& stream)
	{
		stream << "Hello " << name << '\n';
	}

    void printName2(const std::string& name)
    {
        std::ostream& stream = std::cout;
        printName22(name, stream);
    }

    void printName0(const std::string& name)
    {
        std::cout << "Hello " << name << '\n';
    }
};
