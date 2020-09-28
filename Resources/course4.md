# Course Section 4

## Testing non-functional code

### Functional Harness

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
* [ ] Poke-test SideEffects::printName1()
* [ ] Peel SideEffects::printName1() to return a string
* [ ] Peel/slice SideEffects::printName2() to take a stream

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
