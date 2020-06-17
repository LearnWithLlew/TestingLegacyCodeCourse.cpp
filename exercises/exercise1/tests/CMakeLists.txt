set(CMAKE_CXX_STANDARD 17)
set(SOURCE_FILES
        main.cpp
        LegacyTest.cpp
        Test.cpp
        )
add_executable(exercise1 ${SOURCE_FILES} )
target_link_libraries(exercise1 Catch2::Catch2)
