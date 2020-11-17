# Course Section 3

## Testing non-functional code

### Functional Harness

#### System Configuration

**In File:** `exercises/exercise2/tests/ValidateDevelopmentEnvironment.cpp`
* [x] Validate environment
    * [x] Run the test
    * [x] Fix the test

**In File:** `exercises/exercise2/tests/SystemConfigurationTests.cpp`

* [x] Write a Poke test for `initialiseSystem()`
    * Confirmation: Passing test with no verification
* [x] Capture the global variable `rpm`
    * Confirmation: Your approval shows the ending value of rpm
* [x] Capture all global variables 
    * Hint: `#define PRINT(x) #x" = " << x`
    * Confirmation: Your approval shows the ending values of all 10 global variables
* [x] Capture all starting state of global variables as well
    * Confirmation: Your approval shows the starting and ending values
* [x] Write a second test, that does the same as the first test
    * Confirmation: Both tests pass when run separately
* [x] Make and use a function to set the global variables and use it.
    * Hint: `setAllGlobals(....)`
    * Confirmation: Tests pass when run together AND individually
* [x] Make a function to write the code to set the global variables
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
* [x] Write a Poke test for Services.h's `initialiseServices()`
    * Confirmation: Passing test with no verification
* [x] Log all REST calls
    * Confirmation: You can see all 5 calls and results
* [x] Turn on SECURE
    * Confirmation: Your tests no longer work
* [x] Make a preprocessor seam to log if testing
    * Confirmation: Tests work, without result codes
* [x] Allow multiple tests
    * Hint: `logger.str("")`
    * Confirmation: Tests pass when run together AND individually
* [ ] Retro

#### Files

* [ ] Retro

#### Database

* [ ] Retro

