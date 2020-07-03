add_library(exercise1_library INTERFACE)
target_include_directories(exercise1_library
        INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
        )
if(MSVC)
    add_custom_target(exercise1_library.headers SOURCES Legacy.h TrigMath.h)
endif()
