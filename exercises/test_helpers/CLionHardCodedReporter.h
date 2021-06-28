#pragma once

#include "ApprovalTests.hpp"

class CLionHardCodedReporter
{
public:
    static std::shared_ptr<ApprovalTests::Reporter> create_windows_clion_reporter();

    static std::shared_ptr<ApprovalTests::Reporter> create_reporter_preferring_clion();
};
