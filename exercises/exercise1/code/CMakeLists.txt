add_library(exercise1_library TrigMath.cpp TrigMath.h)
target_include_directories(exercise1_library
        PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
        )
