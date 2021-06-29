set(CMAKE_CXX_STANDARD 17)
set(SOURCE_FILES
        main.cpp
        TrigMathTests.cpp
        TrigMathApprovalTests.cpp
        Samples.cpp
        # including the header files here is a hack to get
        # OpenCppCoverage to show the coverage in the headers
        ../code/TrigMath.h
        ValidateDevelopmentEnvironment.cpp)
add_executable(exercise1_tests ${SOURCE_FILES})
target_link_libraries(exercise1_tests exercise1_library Catch2::Catch2 ApprovalTests::ApprovalTests test_helpers::test_helpers)

# Work around Ninja in-source build error
# See https://github.com/approvals/ApprovalTests.cpp/blob/master/doc/TroubleshootingMisconfiguredBuild.md#situation-visual-studio-with-visual-c-compiler-clexe
target_compile_options(exercise1_tests PUBLIC $<$<CXX_COMPILER_ID:MSVC>:/FC>)

add_test(NAME exercise1_tests COMMAND exercise1_tests)
