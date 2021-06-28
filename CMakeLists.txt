cmake_minimum_required(VERSION 3.8)
project(legacy_code_course)

if (MSVC)
    # Enable exceptions for clang-cl
    add_compile_options(/EHsc)
endif ()

set_property(GLOBAL PROPERTY USE_FOLDERS YES)

enable_testing()
add_subdirectory(third_party)
add_subdirectory(exercises)
