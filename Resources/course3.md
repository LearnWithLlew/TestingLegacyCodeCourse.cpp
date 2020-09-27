# Course Section 3

## Testing non-functional code

### Functional Harness

#### System Configuration

**In File:** `exercises/exercise2/tests/ValidateDevelopmentEnvironment.cpp`
* [ ] Validate environment
    * [ ] Run the test
    * [ ] Fix the test

**In File:** `exercises/exercise2/tests/SystemConfigurationTests.cpp`

* [ ] Write a Poke test for `initialiseSystem()`
    * Confirmation: Passing test with no verification
* [ ] Capture the global variable `rpm`
    * Confirmation: Your approval shows the ending value of rpm
* [ ] Capture all global variables 
    * Hint: `#define PRINT(x) #x" = " << x`
    * Confirmation: Your approval shows the ending values of all 10 global variables
* [ ] Capture all starting state of global variables as well
    * Confirmation: Your approval shows the starting and ending values
* [ ] Write a second test, that does the same as the first test
    * Confirmation: Both tests pass when run separately
* [ ] Make and use a function to set the global variables and use it.
    * Hint: `setAllGlobals(....)`
    * Confirmation: Tests pass when run together AND individually
* [ ] Make a function to write the code to set the global variables
    * Hint: Like this, but writing out the actual values of the globals:
        ```cpp
        std::string generateCodeToSetGlobals()
        {
            return "setAllGlobals(4000, 0.01, 0, 0, 0, 1, 2, 3, true, 3.2);";
        }
        ```
    * Confirmation: You can copy the C++ code from standard output into your IDE, and it compiles
* [ ] Retro

#### Adding Logging
**In File:** `exercises/exercise2/tests/LoggingTests.cpp`  
* [ ] Write a Poke test for Services.h's `initialiseServices()`
    * Confirmation: Passing test with no verification
* [ ] Log all REST calls
    * Confirmation: You can see all 5 calls and results
* [ ] Turn on SECURE
    * Confirmation: Your tests no longer work
* [ ] Make a preprocessor seam to log if testing
    * Confirmation: Tests work, without result codes
* [ ] Allow multiple tests
    * Hint: `logger.str("")`
    * Confirmation: Tests pass when run together AND individually
* [ ] Retro

#### Files

* [ ] Retro

#### Database

* [ ] Retro

#### Date and Time
**In File:** `exercises/exercise2/tests/InconsistentTests.cpp`
* [ ] Scrub Inconsistent::print() for time
    * [ ] Poke-test print() in Inconsistent.h
        * Confirmation: Failing test because of date and time
    * [ ] Scrub inconsistent results
    * Hint: `Approvals::verify("text", Options(Scrubbers::createRegexScrubber(R"()", "[replacement]")));`
    * Hint: `\d` matches a digit
    * Hint: `[a-z]` matches lower-case letter
    * Hint: `\d{3}` matches 3 digits 
    * Confirmation: Passing test with scrubbed date
* [ ] Peel Inconsistent::print() to pass in time
    * Hint: `ApprovalTests::DateUtils::createUtcDateTime`
* [ ] Retro

#### Random
**In File:** `exercises/exercise2/tests/InconsistentTests.cpp`
* [ ] Poke-test getId() in Inconsistent.h
* [ ] Make getId() testable
* [ ] Make consistent seed via #ifdef
    * Confirmation: test work when run 2 times 
* [ ] Extract testable function that takes a seed
    * Confirmation: working test without the test seam
* [ ] Extract Testable function that takes a number
    * Confirmation: you can reason out what the result will be before running it.
* [ ] Retro

#### Side Effects
**In File:** `exercises/exercise2/tests/SideEffectsTests.cpp`
* [ ] Poke-test SideEffects::print()
* [ ] Peel SideEffects::print() to return a string
* [ ] Peel/slice SideEffects::print() to take a stream

### Missing Inputs
**In File:** `exercises/exercise2/tests/MissingInputsTests.cpp`
* [ ] Poke-test MissingInputs::getCategory()
* [ ] Get it to 100% coverage
* [ ] Peel to pass in missing inputs 

### Reduce to functional
**In File:** `exercises/exercise2/tests/LoopTests.cpp`
* [ ] Separate a loop
    * Have a loop that squares a number and saves it to a file
    * Turn it into two loops - one does the calculation, the other saves it to the file

### Wrapping Up

* [ ] Retro
