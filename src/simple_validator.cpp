#include "simple_validator.hpp"
#include <stack>

// Helper function to check if a tag is a closing tag
bool isClosingTag(const std::string& tag) {
    return !tag.empty() && tag[0] == '/';
}

// Helper function to remove the slash from a closing tag
std::string stripClosingSlash(const std::string& tag) {
    return isClosingTag(tag) ? tag.substr(1) : tag;
}

// Main XML validation function
bool isValidXmlStructure(const std::string& input) {
    // Check for empty input (invalid XML)
    if (input.empty()) {
        return false;
    }

    std::stack<std::string> tagStack;
    std::size_t i = 0;
    bool foundRoot = false;

    while (i < input.size()) {
        if (input[i] == '<') {
            // Find the end of the tag
            std::size_t closePos = input.find('>', i);
            if (closePos == std::string::npos) return false; // No closing '>', invalid tag

            std::string tag = input.substr(i + 1, closePos - i - 1);
            if (tag.empty()) return false; // Empty tag, invalid

            if (isClosingTag(tag)) {
                // Closing tag logic
                std::string tagName = stripClosingSlash(tag);
                if (tagStack.empty() || tagStack.top() != tagName) return false; // Mismatched closing tag
                tagStack.pop();

                // After root closes, check for any additional content
                if (tagStack.empty() && foundRoot) {
                    if (input.find('<', closePos + 1) != std::string::npos) return false; // Extra elements after root's closing tag
                }
            }
            else {
                // Opening tag logic
                if (tagStack.empty() && foundRoot) return false; // More than one root element
                foundRoot = true;
                tagStack.push(tag);
            }
            i = closePos + 1;
        }
        else {
            i++; // Move to the next character
        }
    }

    return tagStack.empty(); // Valid if stack is empty at end
}