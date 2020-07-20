set(CMAKE_CXX_STANDARD 17)
set(SOURCE_FILES
        InconsistentTests.cpp
        main.cpp
        SystemConfigurationTests.cpp
        LoggingTests.cpp
        Samples.h
        SideEffectsTests.cpp
        )
add_executable(exercise2_tests ${SOURCE_FILES} )
target_link_libraries(exercise2_tests exercise2_library Catch2::Catch2 ApprovalTests::ApprovalTests)


# Work around Ninja in-source build error
# See https://github.com/approvals/ApprovalTests.cpp/blob/master/doc/TroubleshootingMisconfiguredBuild.md#situation-visual-studio-with-visual-c-compiler-clexe
target_compile_options(exercise2_tests PUBLIC $<$<CXX_COMPILER_ID:MSVC>:/FC>)

add_test(NAME exercise2_tests COMMAND exercise2_tests)
