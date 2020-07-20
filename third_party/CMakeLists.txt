if(NOT TARGET ApprovalTests)
    set(LIB_NAME ApprovalTests)
    add_library(${LIB_NAME} INTERFACE)
    target_include_directories(${LIB_NAME} INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
    add_library(${LIB_NAME}::${LIB_NAME} ALIAS ${LIB_NAME})

    # Show files in Visual Studio:
    add_custom_target(
            ApprovalTests_sources
            SOURCES
            ApprovalTests.hpp
            ApprovalTests.v.10.1.1.hpp
    )
    set_target_properties(ApprovalTests_sources PROPERTIES PROJECT_LABEL "ApprovalTests")
endif()

add_subdirectory(catch2)
