cmake_minimum_required(VERSION 3.8)
project(legacy_code_course)

set_property(GLOBAL PROPERTY USE_FOLDERS YES)

enable_testing()
add_subdirectory(third_party)
add_subdirectory(exercises)
add_subdirectory(Resources)
