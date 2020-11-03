# Workshop: Testing Legacy C++ Code effectively with Approval Tests

Course tutors: Llewellyn Falco and Clare Macrae

## Exercises

* **Session 1:**
    * [Resources/course1.md](Resources/course1.md)
    * Code: [exercises/exercise1/](exercises/exercise1/)
* **Session 2:**
    * [Resources/course2.md](Resources/course2.md)
    * Code: [exercises/exercise1/](exercises/exercise1/)
* **Session 3:**
    * [Resources/course3.md](Resources/course3.md)
    * Code: [exercises/exercise2/](exercises/exercise2/)
* **Session 4:**
    * [Resources/course4.md](Resources/course4.md)
    * Code: [exercises/exercise2/](exercises/exercise2/)

## Building the code

### Assumptions

* That you have a C++ compiler and suitable IDE installed
    * There are [some C++ resources on #include <C++>](https://www.includecpp.org/resources/references/#c-language-resources)
* That you have [CMake](https://cmake.org) installed

### Get this code

* Clone or download this repository:
    * [https://github.com/LearnWithLlew/TestingLegacyCodeCourse.cpp](https://github.com/LearnWithLlew/TestingLegacyCodeCourse.cpp)

```bash
git clone https://github.com/LearnWithLlew/TestingLegacyCodeCourse.cpp.git
```

### Using a CMake-aware IDE

* Using Clion, or any other CMake-aware IDE, you should be able to open this repository's directory on your machine, and the IDE will create the project for you.

### Building and Testing Using CMake and CTest

```bash
cd TestingLegacyCodeCourse.cpp
mkdir cmake-build-debug
cd    cmake-build-debug

# Create the build commands:
cmake .. -DCMAKE_BUILD_TYPE=Debug

# Build the project
cmake --build .

# Run the tests
ctest .  -C Debug --output-on-failure
```

## How to set up code coverage

* [Set up Code Coverage on macOS](https://github.com/claremacrae/talks/blob/main/HowTos/Set_up_Code_Coverage_on_macOS.md)
* [Set up Code Coverage on Windows](https://github.com/claremacrae/talks/blob/main/HowTos/Set_up_Code_Coverage_on_Windows.md)

## References and links

* [Workshop: Testing Legacy Code Effectively with Approval Tests](https://github.com/claremacrae/talks/blob/main/Workshop_Testing_Legacy_Code_Effectively_with_Approval_Tests.md#top)


