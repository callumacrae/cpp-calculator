//
//  calculate.cpp
//  calculator
//
//  Created by Callum Macrae on 15/06/2021.
//

#include <iostream>
#include <string>
#include <math.h>

#include "calculate.hpp"

float calculate(const std::string& mathString) {
    std::size_t firstCharPos = mathString.find_first_not_of(' ');
    std::size_t lastCharPos = mathString.find_last_not_of(' ');
    char firstChar = mathString[firstCharPos];
    
    if ((firstChar == '(' || (firstChar >= 'a' && firstChar <= 'z')) && mathString[lastCharPos] == ')') {
        std::size_t firstBracketPos = firstChar == '(' ? firstCharPos : mathString.find_first_of('(');
        float innerResult = calculate(mathString.substr(firstBracketPos + 1, lastCharPos - firstCharPos - 1));
        
        if (firstChar == '(') {
            return innerResult;
        }
        
        std::string function = mathString.substr(firstCharPos, firstBracketPos - firstCharPos);
        
        if (function == "sin") {
            return sin(innerResult);
        } else if (function == "cos") {
            return cos(innerResult);
        } else if (function == "floor") {
            return floorf(innerResult);
        } else if (function == "ceil") {
            return ceilf(innerResult);
        } else if (function == "round") {
            return roundf(innerResult);
        } else {
            throw "@todo work out how to do errors";
        }
    }
    
    int bracketsDeep = 0;
    for (int i = (int) mathString.size() - 1; i >= 0; i--) {
        if (mathString[i] == '(') {
            bracketsDeep++;
        } else if (mathString[i] == ')') {
            bracketsDeep--;
        }
        
        if (bracketsDeep == 0 && (mathString[i] == '-' || mathString[i] == '+')) {
            float left = calculate(mathString.substr(0, i));
            float right = calculate(mathString.substr(i + 1));
            
            return mathString[i] == '-' ? left - right : left + right;
        }
    }
    
    bracketsDeep = 0;
    for (int i = (int) mathString.size() - 1; i >= 0; i--) {
        if (mathString[i] == '(') {
            bracketsDeep++;
        } else if (mathString[i] == ')') {
            bracketsDeep--;
        }
        
        if (bracketsDeep == 0 && (mathString[i] == '*' || mathString[i] == '/')) {
            float left = calculate(mathString.substr(0, i));
            float right = calculate(mathString.substr(i + 1));
            
            return mathString[i] == '*' ? left * right : left / right;
        }
    }
    
    bracketsDeep = 0;
    for (int i = (int) mathString.size() - 1; i >= 0; i--) {
        if (mathString[i] == '(') {
            bracketsDeep++;
        } else if (mathString[i] == ')') {
            bracketsDeep--;
        }
        
        if (bracketsDeep == 0 && mathString[i] == '^') {
            float left = calculate(mathString.substr(0, i));
            float right = calculate(mathString.substr(i + 1));
            
            return pow(left, right);
        }
    }
    
    return std::stof(mathString);
}
