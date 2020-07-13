# Course

## Testing Functional Code

* [x ] Run first test
    * Confirmation: See failure message
* [x ] Get the test to pass
    * Confirmation: See green result
* [x] Test Asin() completely
    * [x ] Check coverage of Asin() with break points
        * [x] Add a breakpoint on every line of Asin()
        * [x ] Remove breakpoint when hit
        * Confirmation: No more breakpoints in Asin()
    * [x] Install OpenCppCoverage in Visual Studio
        * Confirmation: Visual Studio's Tools menu has "Run OpenCppCoverage"
    * [x] Run test coverage
        * Confirmation: See what areas of TrigMath.cpp are green (covered)
    * Confirmation: See 100% coverage of the method
* [x] Test TrigMath completely
    * Confirmation: See 100% coverage of the code
    * Code Coverage reached: 79%
* [x] Explanations and Retrospective

## Testing with Approvals

* [x] Basic approval of Sin() and Cos()
    * Confirmation:
        * a diff tool opened
        * 2 `.approved.txt` files in source control
        * tests are passing
* [ ] Create a function that tests all methods for one value, 1.0 - `Approvals::verify(runEverything(1.0))`
  * Hint: for atan2 , use 0.4 as the second parameter
    * Confirmation: A large `.approved.txt` file
* [ ] Better to-strings, to show function names
    * Confirmation: You can tell which method was called, for each line in `.approved.txt`
* [ ] Test all methods with input value 3.14
    * Confirmation: Another large `.approved.txt` file
* [ ] Make a single test that tests everything for 1.0 and 3.14
    * Hint: read the docs
    * Confirmation: You should have a call to  `Approvals::verifyAll()`
* [ ] Better to-strings, to show function names and input values
    * Confirmation: You can tell which method was called, with which value, for each line in `.approved.txt`
* [ ] Combination approvals - for one input
    * Confirmation: You should have a `CombinationApprovals::verifyAllCombinations()` call
* [ ] Combination approvals - for multiple inputs
    * Confirmation: You have tested `Atan2` with a range of values for both arguments
* [ ] Improve the precision of PI
    * Hint: Use `M_PI`
    * Confirmation: Later digits in the results are different; tests are passing 
* [ ] Turn on IMPROVEMENT_2
    * Confirmation: You can tell us what this did; You know if you should fix the tests or undo the change 
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
