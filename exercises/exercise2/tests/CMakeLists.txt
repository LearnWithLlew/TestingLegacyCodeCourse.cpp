set(CMAKE_CXX_STANDARD 17)
set(SOURCE_FILES
        InconsistentTests.cpp
        main.cpp
        SystemConfigurationTests.cpp
        LoggingTests.cpp
        Samples.h
        )
add_executable(exercise2 ${SOURCE_FILES} )
target_link_libraries(exercise2 exercise2_library Catch2::Catch2 ApprovalTests::ApprovalTests)


# Work around Ninja in-source build error
# See https://github.com/approvals/ApprovalTests.cpp/blob/master/doc/TroubleshootingMisconfiguredBuild.md#situation-visual-studio-with-visual-c-compiler-clexe
target_compile_options(exercise2 PUBLIC $<$<CXX_COMPILER_ID:MSVC>:/FC>)

add_test(NAME exercise2 COMMAND exercise2)
