#include <catch2/catch.hpp>
#include "../code/TrigMath.h"

#include <iostream>

TEST_CASE("Add full breakpoints") {
    // Code to be inserted in to .idea/workspace.xml.
    // You must manually create the first breakpoint, and then quit CLion.
    std::cout << "\n\n\n";
    for(int i = 1; i <= 177; ++i )
    {
        std::cout << "        <line-breakpoint enabled=\"true\" type=\"com.jetbrains.cidr.execution.debugger.OCBreakpointType\">\n"
                     "          <url>file://$PROJECT_DIR$/exercises/exercise1/code/TrigMath.h</url>\n"
                     "          <line>" << i << "</line>\n"
                     "          <option name=\"timeStamp\" value=\"50\" />\n"
                     "        </line-breakpoint>\n";
    }
    std::cout << "\n\n\n";
}


TEST_CASE("Test Sin") {
    TrigMath math;
    REQUIRE(Approx(0.8676960543) == math.Sin(3.4));
}

TEST_CASE("Test Asin") {
    TrigMath math;
    REQUIRE(Approx(-0.7753974966) == math.Asin(-0.7));
    REQUIRE(Approx(0.304692654) == math.Asin(0.3));
    REQUIRE(Approx(1.119769515) == math.Asin(0.9));
    REQUIRE(isnan(math.Asin(1.2)));
}
