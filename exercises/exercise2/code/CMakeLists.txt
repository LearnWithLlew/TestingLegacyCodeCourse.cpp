add_library(exercise2_library SystemConfiguration.h SystemConfiguration.cpp)
target_include_directories(exercise2_library
        PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
        )
