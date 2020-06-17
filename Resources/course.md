# Course

## Testing Functional Code

* [x] Run first test
    * Confirmation: See failure message
* [x] Get the test to pass
    * Confirmation: See green result
* [x] Run test coverage
    * Confirmation: See what areas of TrigMath.h are green (covered)
* [x] Test Asin() completely
    * Confirmation: See 100% coverage of the method
* [ ] Test TrigMath completely
    * Confirmation: See 100% coverage of the code
    * Code Coverage reached: ______%
* [ ] Explanations and Retrospective

## Testing with Approvals

* [ ] Basic approval of Sin() and Cos()
    * Confirmation:
        * a diff tool opened
        * 2 `.approved.txt` files in source control
        * tests are passing
* [ ] Create a function that tests all methods for one value, 1.0 - `Approvals::verify(runEverything(1.0))`
    * Confirmation: A large `.approved.txt` file
* [ ] Better to-strings, to show function names
    * Confirmation: You can tell which method was called, for each line in `.approved.txt`
* [ ] Test all methods with input value 3.14
    * Confirmation: Another large `.approved.txt` file
* [ ] Make a single test that tests everything for 1.0 and 3.14
    * Confirmation: You should have a call to  `Approvals::verifyAll()`
* [ ] Better to-strings, to shown function names and input values
    * Confirmation: You can tell which method was called, with which value, for each line in `.approved.txt`
* [ ] Combination approvals - for one input
    * Confirmation: You should have a `CombinationApprovals::verifyAllCombinations()` call
* [ ] Combination approvals - for multiple inputs
    * Confirmation: You have tested `Atan2` with a range of values for both arguments
* [ ] Combination approvals - for function pointer inputs
    * Confirmation: You are testing without using without using `runEverything()`
        * One of your arguments is vector of function pointers
