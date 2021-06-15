//
//  calculate.cpp
//  calculator
//
//  Created by Callum Macrae on 15/06/2021.
//

#include <iostream>
#include <regex>
#include <string>

#include "calculate.hpp"

enum CharType {
    CharTypeNumber, CharTypeOperation, CharTypeWhitespace, CharTypeUnknown
};

static CharType getCharType(char character) {
    if (character >= '0' && character <= '9') {
        return CharTypeNumber;
    }
    
    if (character == '+' || character == '-' || character == '/' || character == '*') {
        return CharTypeOperation;
    }
    
    if (character == ' ') {
        return CharTypeWhitespace;
    }
    
    return CharTypeUnknown;
}

int calculate(const std::string& mathString) {
    int aStart = -1;
    int aEnd = -1;
    char operation = 0;
    int bStart = -1;
    int bEnd = -1;
    
    for (int i = 0; i < mathString.size(); i++) {
        CharType type = getCharType(mathString[i]);
        
        switch (type) {
            case CharTypeNumber:
                if (aStart == -1) {
                    aStart = i;
                } else if (aEnd != -1 && bStart == -1) {
                    bStart = i;
                }
                break;
                
            case CharTypeOperation:
                operation = mathString[i];
                // break;
                
            case CharTypeWhitespace:
                if (aStart != -1 && aEnd == -1) {
                    aEnd = i;
                } else if (bStart != -1 && bEnd == -1) {
                    bEnd = i;
                }
                break;
                
            case CharTypeUnknown:
                throw "SYNTAX ERROR!!!";
        }
    }
    
    if (!operation) {
        throw "WHAT?!?!?!";
    }
    
    std::string aStr = mathString.substr(aStart, aEnd - aStart + 1);
    std::string bStr = mathString.substr(bStart, bEnd - bStart + 1);
    
    int a = std::stoi(aStr);
    int b = std::stoi(bStr);
    
    int result;
    if (operation == '+') {
        result = a + b;
    } else if (operation == '-') {
        result = a - b;
    } else if (operation == '*') {
        result = a * b;
    } else if (operation == '/') {
        result = a / b;
    } else {
        throw "UNSUPPORTED OPERATION!!!";
    }
    
    return result;
}
