set(LIB_NAME test_helpers)
add_library(
        ${LIB_NAME}
        CLionHardCodedReporter.cpp
        CLionHardCodedReporter.h
        )
target_include_directories(
        ${LIB_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(
        ${LIB_NAME} PUBLIC ApprovalTests::ApprovalTests)
add_library(
        ${LIB_NAME}::${LIB_NAME} ALIAS ${LIB_NAME})
