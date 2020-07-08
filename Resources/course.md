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

* [X] Basic approval of Sin() and Cos()
    * Confirmation:
        * a diff tool opened
        * 2 `.approved.txt` files in source control
        * tests are passing
* [x] Create a function that tests all methods for one value, 1.0 - `Approvals::verify(runEverything(1.0))`
  * Hint: for atan2 , use 0.4 as the second parameter
  * Confirmation: A large `.approved.txt` file
* [X] Better to-strings, to show function names
    * Confirmation: You can tell which method was called, for each line in `.approved.txt`
* [X] Test all methods with input value 3.14
    * Confirmation: Another large `.approved.txt` file
* [X] Make a single test that tests everything for 1.0 and 3.14
    * Hint: read the docs
    * Confirmation: You should have a call to  `Approvals::verifyAll()`
* [X] Better to-strings, to show function names and input values
    * Confirmation: You can tell which method was called, with which value, for each line in `.approved.txt`
* [X] Combination approvals - for one input
    * Confirmation: You should have a `CombinationApprovals::verifyAllCombinations()` call
* [ ] Combination approvals - for multiple inputs
    * Confirmation: You have tested `Atan2` with a range of values for both arguments
* [ ] Combination approvals - for function pointer inputs
    * Confirmation: You are testing without using `runEverything()`
        * One of your arguments is vector of function pointers
