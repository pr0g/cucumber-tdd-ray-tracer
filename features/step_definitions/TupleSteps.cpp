#include <cucumber-cpp/autodetect.hpp>
#include <vector>

#include "tuple.h"

using cucumber::ScenarioScope;

struct TupleContext {
    std::vector<Tuple> tuples;
    Tuple result;
};

GIVEN("^a\\d+ <\\- tuple\\((-?\\d+), (-?\\d+), (-?\\d+), (-?\\d+)\\)$") {
    REGEX_PARAM(float, n1);
    REGEX_PARAM(float, n2);
    REGEX_PARAM(float, n3);
    REGEX_PARAM(float, n4);
    
    ScenarioScope<TupleContext> context;
    Tuple tuple = Tuple(n1, n2, n3, n4);
    context->tuples.push_back(tuple);
}

THEN("^a\\d+ \\+ a\\d+ = tuple\\((-?\\d+), (-?\\d+), (-?\\d+), (-?\\d+)\\)$") {
    REGEX_PARAM(double, expected1);
    REGEX_PARAM(double, expected2);
    REGEX_PARAM(double, expected3);
    REGEX_PARAM(double, expected4);

    Tuple expected = Tuple(expected1, expected2, expected3, expected4);

    ScenarioScope<TupleContext> context;
    Tuple result{};
    for (const auto& tuple : context->tuples) {
        result = result + tuple;
    }

    EXPECT_NEAR(result.x, expected.x, std::numeric_limits<float>::epsilon());
    EXPECT_NEAR(result.y, expected.y, std::numeric_limits<float>::epsilon());
    EXPECT_NEAR(result.z, expected.z, std::numeric_limits<float>::epsilon());
    EXPECT_NEAR(result.w, expected.w, std::numeric_limits<float>::epsilon());
}
