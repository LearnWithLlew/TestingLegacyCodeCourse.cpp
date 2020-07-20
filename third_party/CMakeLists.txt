if(NOT TARGET ApprovalTests)
    set(LIB_NAME ApprovalTests)
    add_library(${LIB_NAME} INTERFACE)
    target_include_directories(${LIB_NAME} INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
    add_library(${LIB_NAME}::${LIB_NAME} ALIAS ${LIB_NAME})

    # Show files in Visual Studio:
    add_custom_target(
            third_party_sources
            SOURCES
            ApprovalTests.hpp
            ApprovalTests.v.10.2.0.hpp
            catch2/include/catch2/catch.hpp
            catch2/include/catch2/catch.v2.11.0.hpp
    )
    set_target_properties(third_party_sources PROPERTIES PROJECT_LABEL "third_party")
endif()

add_subdirectory(catch2)
