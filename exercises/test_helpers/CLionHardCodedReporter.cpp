#include "CLionHardCodedReporter.h"

std::shared_ptr<ApprovalTests::Reporter> CLionHardCodedReporter::create_clion_reporter() {
    auto path = R"(C:\Program Files (x86)\JetBrains\CLion 2021.1.2\bin\clion64.exe)";
    auto arguments = "diff {Received} {Approved}";
    return ApprovalTests::CustomReporter::create(path, arguments);
}
