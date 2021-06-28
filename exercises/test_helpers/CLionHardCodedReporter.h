#pragma once

#include "ApprovalTests.hpp"

class CLionHardCodedReporter
{
public:
    static std::shared_ptr<ApprovalTests::Reporter> create_clion_reporter();
};
