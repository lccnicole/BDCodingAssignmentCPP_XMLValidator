#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include "simple_validator.hpp"

using namespace std;

// Function to run the tests
void runTests(const vector<tuple<string, bool>>& test_cases) {
    int failed_count = 0;

    for (const auto& test_case : test_cases) {
        const auto& input = get<0>(test_case);
        const auto& expected = get<1>(test_case);

        auto result = DetermineXml(input);
        auto result_str = result ? "Valid" : "Invalid";
        auto expected_str = expected ? "Valid" : "Invalid";

        if (result == expected) {
            cout << "OK ";
        }
        else {
            cout << "NG ";
            failed_count++;
            cout << "(Expected: " << expected_str << ") ";
        }
        cout << input << ": " << result_str << endl;
    }

    cout << "Result: " << (test_cases.size() - failed_count) << "/" << test_cases.size() << " passed.\n";
}

int main(int argc, char* argv[]) {
    // Inline test cases to validate XML string functionality
    vector<tuple<string, bool>> test_cases = {
        {"<Design><Code>hello world</Code></Design>", true},                   // normal case
        {"<Design><Code>hello world</Code></Design><People>", false},          // no closing tag for "People"
        {"<People><Design><Code>hello world</People></Code></Design>", false}, // "/Code" should come before "/People"
        {"<People age=”1”>hello world</People>", false},                       // improper attributes in tag
    };

    // Run tests and display results
    runTests(test_cases);
    return 0;
}
