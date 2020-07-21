# Course

## Testing Functional Code

* [ ] Run first test
    * Confirmation: See failure message
* [ ] Get the test to pass
    * Confirmation: See green result
* [ ] Test Asin() completely
    * [ ] Write a new test for Asin()
    * [ ] Check coverage of Asin() with break points
        * [ ] Add a breakpoint on every line of Asin()
        * [ ] Remove breakpoint when hit
        * Confirmation: No more breakpoints in Asin()
    * [ ] Install OpenCppCoverage in Visual Studio
        * Confirmation: Visual Studio's Tools menu has "Run OpenCppCoverage"
    * [ ] Run test coverage
        * Confirmation: See what areas of TrigMath.cpp are green (covered)
    * Confirmation: See 100% coverage of the Asin() method
* [ ] Test TrigMath completely
    * Confirmation: See 100% coverage of the code
    * Code Coverage reached: ______%
* [ ] Explanations and Retrospective

## Testing with Approvals
### Basic ApprovalTests
* [ ] Basic approval of Sin() and Cos()
    * Confirmation:
        * a diff tool opened
        * 2 `.approved.txt` files in source control
        * tests are passing
* [ ] Create a function that tests all 13 methods in TrigMath for one value, 1.0 -    
  `Approvals::verify(runEverything(1.0))`
  * Use std::stringstream
  * Hint: for atan2 , use 0.4 as the second parameter
  * Confirmation: A large `.approved.txt` file with 13 values
* [ ] Better to-strings, to show function names
    * Confirmation: You can tell which method was called, for each line in `.approved.txt`
* [ ] Test all methods with input value 3.14
    * Confirmation: Another large `.approved.txt` file
### Verify List of Inputs
* [ ] Make a single test that tests everything for 1.0 and 3.14
    * Hint: read the docs
    * Confirmation: You should have a call to  `Approvals::verifyAll()`
* [ ] Test -0.1, 0, 0.2, 0.8 for everything
    * Confirmation: Everything except Atan2 should be covered
### Seeing Failures
* [ ] Improve the precision of PI
    * Hint: Use `M_PI`
    * Confirmation: Later digits in the results are different; tests are passing 
* [ ] Turn on IMPROVEMENT_2
    * Confirmation: You can tell us what this did; You know if you should fix the tests or undo the change 
* [ ] Better to-strings, to show function names and input values
    * Confirmation: You can tell which method was called, with which value, for each line in `.approved.txt`
### Combinations of Inputs
* [ ] Combination approvals - for one input
    * Confirmation: You should have a `CombinationApprovals::verifyAllCombinations()` call
* [ ] Combination approvals - for multiple inputs
    * Confirmation: You have tested `Atan2` with a range of values for both arguments

### Finishing Off
* [ ] Explanations and Retrospective

### Extra Credit:

* [ ] Test Sin() using a method pointer and standard Catch2 `REQUIRE`
    * Hints:
    ```
    typedef  int (Fred::*FredMemFn)(char x, float y);
    #define CALL_MEMBER_FN(object,ptrToMember)  ((object).*(ptrToMember))
    int ans = CALL_MEMBER_FN(fred,p)('x', 3.14);
    ```
      * from: https://isocpp.org/wiki/faq/pointers-to-members#typedef-for-ptr-to-memfn
* [ ] Combination approvals - for function pointer inputs
    * Confirmation: You are testing without using `runEverything()`
        * One of your arguments is vector of function pointers

## Testing non-functional code

### Functional Harness

#### System Configuration

* [ ] Write a Poke test
* [ ] Capture all global variables
    * Hint: `#define PRINT(x) #x" = " << x`
* [ ] Write a second test
* [ ] Make a function to set the global variables
* [ ] Make a function to write the code to set the global variables
* [ ] Move helper functions
    * [ ] preprocessor
    * [ ] separate header
    * [ ] tests
* [ ] Retro

#### Adding Logging

* [ ] Write a Poke test for Services::initialiseServices()
* [ ] Log all REST calls
* [ ] Turn on SECURE
    * Confirmation: Your tests no longer work
* [ ] Make a preprocessor seam to log if testing
    * Confirmation: Tests work, without result codes
* [ ] Allow multiple tests
* [ ] Retro

#### Files

* [ ] Retro

#### Database

* [ ] Retro

#### Date and Time

* [ ] Poke-test print() in Inconsistent.h
* [ ] Scrub Inconsistent::print() for time
    * Hint: `Approvals::verify("text", Options(Scrubbers::createRegexScrubber(R"()", "[replacement]")));`
    * Hint: `\d` matches a digit
    * Hint: `[a-z]` matches lower-case letter
* [ ] Peel Inconsistent::print() to pass in time
* [ ] Retro

#### Random

* [ ] Poke-test getId() in Inconsistent.h
* [ ] Make getId() testable
* [ ] Make consistent seed via #ifdef
    * Confirmation: test work when run 2 times 
* [ ] Extract testable function that takes a seed
    * Confirmation:working test without #ifdef
* [ ] Extract Testable function that takes a number
    * Confirmation: you can reason out what the result will be before running it.
* [ ] Retro

#### Side Effects

* [ ] Poke-test SideEffects::print()
* [ ] Peel SideEffects::print() to return a string
* [ ] Peel/slide SideEffects::print() to take a stream

### Missing Inputs

* [ ] Poke-test MissingInputs::getCategory()
* [ ] Get it to 100% coverage
* [ ] Peel to pass in missing inputs 

### Reduce to functional

* [ ] Peel: Extract a functional core
    * [ ] Test Legacy::getCategory()
    * [ ] Test Legacy::printName() - passing in a stream
    * [ ] Test Legacy::printName() - returning a string
* [ ] Slice: Pass in a slice
* [ ] Separate a loop
    * Have a loop that squares a number and saves it to a file
    * Turn it in to two loops - one does the calculation, the other saves it to the file

### Wrapping Up

* [ ] Retro
