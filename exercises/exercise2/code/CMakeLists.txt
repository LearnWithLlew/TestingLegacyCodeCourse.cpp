add_library(exercise2_library
        Inconsistent.h
        MissingInputs.h
        SystemConfiguration.h
        SystemConfiguration.cpp
        Services.h
        SideEffects.h
        third_party_code.h
        )
target_include_directories(exercise2_library
        PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
        )
