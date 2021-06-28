#pragma once

// Do Not Touch This Code

#include <string>
#include <exception>

namespace _third_party_code_
{
    int rest_call( std::string url, std::string action, int key )
    {
#ifdef SECURE
        throw std::runtime_error( "I pitty the fool that tries to call this service "
                                  "without the proper authorization" );
#endif
        return 200;
    }
}
