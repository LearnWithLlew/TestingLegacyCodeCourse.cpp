set(CMAKE_CXX_STANDARD 17)
set(SOURCE_FILES
        main.cpp
        LegacyTest.cpp
        Test.cpp
        # including the header files here is a hack to get
        # OpenCppCoverage to show the coverage in the headers
        ../code/Legacy.h
        ../code/TrigMath.h
        )
add_executable(exercise1 ${SOURCE_FILES} )
target_link_libraries(exercise1 exercise1_library Catch2::Catch2)
