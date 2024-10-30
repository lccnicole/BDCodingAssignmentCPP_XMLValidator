// main.cpp

#include "simple_validator.hpp"
#include <iostream>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: checker.exe <XML_string>\n";
        return 1;
    }

    std::string xmlContent = argv[1];
    if (isValidXmlStructure(xmlContent)) {
        std::cout << "Valid\n";
    } else {
        std::cout << "Invalid\n";
    }

    return 0;
}
