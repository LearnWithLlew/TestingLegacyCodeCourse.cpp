#include <catch2/catch.hpp>
#include "TrigMath.h"

#include <iostream>

TEST_CASE("Add full breakpoints") {
    for(int i = 1; i <= 177; ++i )
    {

        std::cout << "        <line-breakpoint enabled=\"true\" type=\"com.jetbrains.cidr.execution.debugger.OCBreakpointType\">\n"
                     "          <url>file://$PROJECT_DIR$/exercises/exercise1/code/TrigMath.h</url>\n"
                     "          <line>" << i << "</line>\n"
                     "          <option name=\"timeStamp\" value=\"50\" />\n"
                     "        </line-breakpoint>\n";
    }
}


TEST_CASE("Test Sin") {
    TrigMath math;
    REQUIRE(Approx(0.0) == math.Sin(3.4));
}
