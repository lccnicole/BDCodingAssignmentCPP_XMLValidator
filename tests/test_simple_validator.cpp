// test_simple_validator.cpp

#include "simple_validator.hpp"
#include <gtest/gtest.h>
#include <tuple>


// Parameterized test fixture for validating XML strings
class SimpleValidatorTest : public ::testing::TestWithParam<std::tuple<std::string, bool>> {};


// Parameterized test to reuse the test cases in an automated environment
TEST_P(SimpleValidatorTest, XmlValidation) {
    const auto& [input, expected] = GetParam();
    EXPECT_EQ(isValidXmlStructure(input), expected) << "Failed on input: " << input;
}

// Inline test cases
INSTANTIATE_TEST_SUITE_P(
    XmlTestCases,
    SimpleValidatorTest,
    ::testing::Values(
        std::make_tuple("<Design><Code>hello world</Code></Design>", true), // Valid XML
        std::make_tuple("<Design><Code>hello world</Code></Design><People>", false), // Multiple root elements
        std::make_tuple("<People><Design><Code>hello world</People></Code></Design>", false), // Improperly nested tags
        std::make_tuple("<People age=”1”>hello world</People>", false), // Attributes not allowed
        std::make_tuple("<tutorial date=\"01 / 01 / 2000\">XML</tutorial>", false),
        std::make_tuple("<tutorial date=\"01 / 01 / 2000\">XML</tutorial date=\"01 / 01 / 2000\">", true)
    )
);

INSTANTIATE_TEST_SUITE_P(
    AdditionalXmlTestCases,
    SimpleValidatorTest,
    ::testing::Values(
        std::make_tuple("<root><parent><child>content</child></parent></root>", true), // Valid Nested Tags
        std::make_tuple("<self-closing />", false), //Single Self - Closing Tag(treated as invalid)
        std::make_tuple("<open><inner>content</wrongclose></open>", false), //Mismatched Tag Names (treated as invalid)
        std::make_tuple("content</only-closing>", false), //Missing Opening Tag (treated as invalid)
        std::make_tuple("<note date=\"2024-01-01\">Remember this</note>", false), //Attributes in Opening Tag(treated as invalid)
        std::make_tuple("<html><body><p>Text</p></body></html>", true), //Correctly Nested Multiple Tags
        std::make_tuple("<catalog><book><title>Title1</title></book><book><title>Title2</title></book></catalog>", true), //Nested Tags with Sibling Elements
        std::make_tuple("<root><parent><child>content</parent></child></root>", false), //Unclosed Tag with Nested Content (treated as invalid)
        std::make_tuple("<empty></empty>", true), //Empty Tags
        std::make_tuple("<unclosed>", false), // Missing closing tag (treated as invalid)
        std::make_tuple("<store><book><author><name>Author</name></author><title>Book Title</title></book></store>", true), //Complex Nested Tags
        std::make_tuple("<root1><child>data</child></root1><root2><child>data</child></root2>", false), //Multiple Root Elements
        std::make_tuple("", false), // Empty string (treated as invalid)
        std::make_tuple("<a><b>text</a></b>", false), //Improperly Nested Tags
        std::make_tuple("<root attr=\"value\">data</root>", false) //Tag with Attributes(treated as Invalid)
    )
);
