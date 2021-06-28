#define APPROVALS_CATCH
#include <ApprovalTests.hpp>

#include "CLionHardCodedReporter.h"

// This makes Approval Tests use CLion's diff tool to allow verification and show differences
// between received and approved files.
// We use this during courses to allow CLion's Projector plug-in to work with Approval Tests.
// Beware that the CLionHardCodedReporter::create_clion_reporter() implementation contains
// a hard-coded path to a CLion installation on Windows.
auto defaultReporterDisposer =
        ApprovalTests::Approvals::useAsDefaultReporter(
    CLionHardCodedReporter::create_windows_clion_reporter());
