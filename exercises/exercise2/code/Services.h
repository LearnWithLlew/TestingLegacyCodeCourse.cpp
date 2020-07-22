#pragma once

#include <iostream>
#include <sstream>

#include "third_party_code.h"

std::stringstream logger;

int RestCall(std::string url, std::string action, int key)
{
    logger << "RestCall: url:" << url << "," << "action:" << action << "," << "key:" << key << std::endl;
    int result =_third_party_code_::rest_call(url, action, key);
    logger << "result: " << result << std::endl;
    return result;
}

void initialiseServices()
{
    int key = 42;
    int result = RestCall("https://postgresdatabase.acme.com", "start", key);
    if ( result == 200 )
    {
        key = key + 100;
        result = RestCall("https://kafka.acme.com", "subscribe", key);
        if ( result == 200 )
        {
            result = RestCall("https://cache.acme.com", "load", key);
            if ( result != 200 )
            {
                std::cout << "Error starting cache\n";
            }
            result = RestCall("https://search.acme.com", "index", key);
            if ( result != 200 )
            {
                std::cout << "Error indexing search\n";
            }
            result = RestCall("https://creditcardprocessor.acme.com", "charge", key);
            if ( result != 200 )
            {
                std::cout << "Error charging credit card\n";
            }
        }
    }
}
