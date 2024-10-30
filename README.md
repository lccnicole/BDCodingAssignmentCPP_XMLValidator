### SimpleXMLValidator Explanation 

-   **`simple_validator.hpp` and `simple_validator.cpp`**:
    
    -   Implements the main XML validation function, `isValidXmlStructure`, with helper functions to handle parsing tags, identifying tag types, and enforcing correct XML structure.
    -   The function uses a `std::stack` to track nested tags, ensuring each opening tag has a matching closing tag and that the XML string contains only a single root element.
-   **`main.cpp`**:
    
    -   Provides a simple interface for manually testing XML strings by taking predefined test cases.
    -   Outputs "Valid" or "Invalid" based on the result of the validation function.
-   **Unit Testing with Google Test**:
    
    -   The tests validate a variety of XML structures, including:
        -   Properly nested XML.
        -   Multiple root elements (invalid case).
        -   Improperly nested elements.
        -   Attributes within tags, which are treated as invalid.
          - Valid Nested Tags
        - Single Self-Closing Tag 
        - Mismatched Tag Names
        - Missing Opening Tag
        - Attributes in Opening Tag
        - Correctly Nested Multiple Tags
        - Nested Tags with Sibling Elements
        - Unclosed Tag with Nested Content
        - Empty Tags
        - Only Opening Tag
        - Complex Nested Tags
        - Tag with Attributes(treated as Invalid)
        
    -   The unit tests are implemented in `test_simple_validator.cpp` and are run using the Google Test framework.

### Notable Design Decisions

1.  **Balanced Code Structure**:
    
    -   The validation logic is implemented in a single function, `isValidXmlStructure`, but split into helper functions (`isClosingTag`, `stripClosingSlash`) to enhance readability without over-complicating the code. This structure ensures the code is easy to maintain and extend.
2.  **Helper Functions**:
    
    -   Helper functions improve readability by abstracting operations like detecting closing tags and cleaning tag names. This decision balances clarity and conciseness without veering into excessive modularization.
3.  **CMake Project Setup**:
    
    -   The project is structured with CMake, which is compatible with various development environments, ensuring easy configuration and cross-platform support.

### Instructions for Running and Testing

1.  **Build the Project**:
    -   Run `cmake .` from the root directory, then `make` (or use Visual Studio if on Windows).
2.  **Running the Console Application**:
    -   The main application can be run by executing `checker` (or `checker.exe` on Windows) with an XML string as a command-line argument.
3.  **Running Unit Tests**:
    -   Unit tests can be executed with `ctest -V` or by running `test_checker` directly in the terminal.
 4. **Additional Testing with `run_tests.bat`**
	 - For convenience, a `run_tests.bat` file has been created to automate testing with predefined XML test cases. Run it by double-clicking the file or executing `run_tests.bat` in a command prompt to see the results.

### Future Considerations

1.  **Self-Closing and Attribute Handling**:
    -   Future extensions could include support for self-closing tags (`<tag />`) and attribute handling.
2.  **Error Reporting**:
    -   Enhancements to report the specific line and position of validation errors could improve debugging for XML validation.