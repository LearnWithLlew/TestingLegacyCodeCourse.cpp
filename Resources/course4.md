# Course Section 4

## Testing non-functional code

### Functional Harness

#### Date and Time

> **Scenario:** In this scenario, we are learning how to use ApprovalTests to deal with methods that produce inconsistent results.   
> Because the most common variant of this deals with dates and times, that will be our example.

**In File:** `exercises/exercise2/tests/InconsistentTests.cpp`

> **Step:** First we are going to learn how to pretend that results are consistent.

* [x] Scrub Inconsistent::print() for time
    * [x] Poke-test print() in Inconsistent.h
        * Confirmation: Failing test because of date and time
    * [x] Scrub inconsistent results
    * Hint: `Approvals::verify("text", Options(Scrubbers::createRegexScrubber(R"()", "[replacement]")));`
    * Hint: `\d` matches a digit
    * Hint: `[a-z]` matches lower-case letter
    * Hint: `\d{3}` matches 3 digits 
    * Confirmation: Passing test with scrubbed date

> **Step:** Next we are going to learn how to change the code to produce consistent results.

* [x] Peel Inconsistent::print() to pass in time
    * Hint: `ApprovalTests::DateUtils::createUtcDateTime`
* [x] Retro

#### Random

> **Scenario:** In this scenario, we are going to look at inconsistency that is embedded deeper in the code. We are going to look at a range of options to make the code consistent.  
> Because randomness is often a problem for testing, that will be our example.

**In File:** `exercises/exercise2/tests/InconsistentTests.cpp`

* [x] Poke-test getId() in Inconsistent.h
  
> **Step:** Let's make quick hacks to get getId() under passing tests

* [x] Make consistent seed via #ifdef
    * Confirmation: test work when run 2 times 

> **Step:** Let's change getId() to make it possible to test without hacks

* [x] Extract testable function that takes a seed
    * Confirmation: working test without the test seam
* [x] Extract Testable function that takes a number
    * Confirmation: you can reason out what the result will be before running it.
* [x] Retro

#### Side Effects

> **Scenario:** In this scenario, we are going to look at code that only produces side-effects, that is, it does not return its results.  
> Unlike last time, where we only captured the results with hacks, this time we are going to change the code so hacks are not needed.  
> A common scenario is writing to output. so that will be our example. 

**In File:** `exercises/exercise2/tests/SideEffectsTests.cpp`

* [x] Poke-test SideEffects::printName1()
* [x] Peel SideEffects::printName1() to return a string
* [x] Peel/slice SideEffects::printName2() to take a stream

### Missing Inputs

> **Scenario:** This scenario is about splitting up code, so that hard-to-set-up scenarios become easily testable.

**In File:** `exercises/exercise2/tests/MissingInputsTests.cpp`

* [x] Poke-test MissingInputs::getCategory()
* [x] Get it to 100% coverage
* [x] Peel to pass in missing inputs 

### Reduce to functional

> **Scenario:** A common problem is how to separate a loop to be functional. We are going to practice doing this.

**In File:** `exercises/exercise2/tests/LoopTests.cpp`

* [ ] Separate a loop
    * Have a loop that squares a number and saves it to a file
    * Turn it into two loops - one does the calculation, the other saves it to the file

### Wrapping Up

* [x] Retro
