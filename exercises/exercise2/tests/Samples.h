#ifndef LEGACY_CODE_COURSE_SAMPLES_H
#define LEGACY_CODE_COURSE_SAMPLES_H

#include <catch2/catch.hpp>

class SystemConfiguration
{
};

SystemConfiguration start(SystemConfiguration config)
{
    return config;
}

TEST_CASE("Test Setup") {
    SystemConfiguration startingConfig;
    SystemConfiguration ending = start(startingConfig);

}

#endif //LEGACY_CODE_COURSE_SAMPLES_H
