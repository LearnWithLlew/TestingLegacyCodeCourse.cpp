# Course Section 1 

## Testing Functional Code

**In File:** `exercises/exercise1/tests/ValidateDevelopmentEnvironment.cpp`

* [x] Validate environment
    * [x] Run the test
    * [x] Fix the test

**In File:** `exercises/exercise1/tests/TrigMathTests.cpp`

**Scenario:** In this scenario, we are going to look at getting high test coverage over existing, working code.  
We are going to start with code that is simpler to test, so you can figure out what it does by running it, and then preserving its behavior with tests. 

* [x] Run first test
    * [x] Uncomment the CHECK line
    * Confirmation: See failure message
* [x] Get the test to pass
    * Confirmation: See green result
* [ ] Test Asin() completely
    * [x] Write a new test for Asin()
    * [ ] Check coverage of Asin() with break points
        * [ ] Add a breakpoint on every line of Asin()
        * [ ] Remove breakpoint when hit
        * Confirmation: No more breakpoints in Asin()
* [ ] **EITHER Set up code coverage measurement in CLion**
    * [x] Select "Debug-Visual Studio clang" configuration
        * Confirmation: The CLion toolbar shows you can run "Test Asin | **Debug-Visual Studio clang**"
    * [x] Select "Run > Run 'Test Asin' with C/C++ Coverage Plugin"
        *  Confirmation: You see a message "Missing compilation flags"
    * [x] Click the blue Create text - if you can't see it, go to CLion's Event Log.
        * Confirmation: The CLion toolbar shows you can run "Test Asin | **Debug-Visual Studio clang-Coverage**"
* [ ] **OR Set up code coverage measurement in Visual Studio**
    * [ ] **Or**  OpenCppCoverage in Visual Studio
        * Confirmation: Visual Studio's Tools menu has "**Run OpenCppCoverage**"
* [x] Run test coverage
    * Confirmation: See what areas of TrigMath.cpp are green (covered)
    * Confirmation: See 100% coverage of the Asin() method
* [ ] Test TrigMath completely
    * Confirmation: See 100% coverage of the code
    * Code Coverage reached: ______%
* [ ] Explanations and Retrospective

## Homework

* [ ] Print out the [homework sheet](https://github.com/LearnWithLlew/TestingLegacyCodeCourse.slides/raw/master/Homework%20Printouts%20-%20Week%201.pdf) and keep it by your desk, to increase your awareness throughout the week.

### Homework details

* [ ] Redo today’s coding exercises on your own computer
    * Start from the code on the [master branch](https://github.com/LearnWithLlew/TestingLegacyCodeCourse.cpp)
    * If you want to see the code we wrote together, check the [other branches](https://github.com/LearnWithLlew/TestingLegacyCodeCourse.cpp/branches)
* [ ] **Count** Number of times you encounter a **functional** method at work this week
* [ ] (Optional) If you **write** any **tests** for those methods, please **make a note** so we can share at the start of next week.

