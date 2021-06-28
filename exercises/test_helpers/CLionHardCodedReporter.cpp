#include "CLionHardCodedReporter.h"

using namespace ApprovalTests;

// This makes Approval Tests use CLion's diff tool to allow verification and show differences
// between received and approved files.
// We use this during courses to allow CLion's Projector plug-in to work with Approval Tests.
// Beware that the implementation contains
// a hard-coded path to a CLion installation on Windows.
std::shared_ptr<Reporter> CLionHardCodedReporter::create_windows_clion_reporter()
{
    auto path = R"(C:\Program Files (x86)\JetBrains\CLion 2021.1.2\bin\clion64.exe)";
    auto arguments = "diff {Received} {Approved}";
    return CustomReporter::create( path, arguments );
}
std::shared_ptr<Reporter> CLionHardCodedReporter::create_reporter_preferring_clion()
{

    std::vector<std::shared_ptr<ApprovalTests::Reporter>> candidate_reporters;

    if ( SystemUtils::isWindowsOs() )
    {
        candidate_reporters.push_back( create_windows_clion_reporter() );
    }

    // Fall back on the standard default reporter, if the above does not work:
    candidate_reporters.push_back( std::make_shared<DiffReporter>() );

    return std::make_shared<FirstWorkingReporter>( candidate_reporters );
}
