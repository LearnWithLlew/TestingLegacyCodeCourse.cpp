#pragma once

#include <cstdlib>
#include <ctime>
#include <string>
#include <iostream>

class SideEffects
{
public:
	std::string printName2(const std::string& name)
	{
		std::stringstream ss;
		ss << "Hello " << name << '\n';
		auto result = ss.str();
		return result;
	}

    // Not all outputs passed out
    void printName(const std::string& name)
    {
	    std::cout << printName2(name);
    }

	void printName4(const std::string& name, std::ostream& basic_ostream)
	{
		basic_ostream << "Hello " << name << '\n';
	}

	void printName3(const std::string& name)
	{
		printName4(name, std::cout);
	}
};
