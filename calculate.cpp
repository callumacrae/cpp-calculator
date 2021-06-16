//
//  calculate.cpp
//  calculator
//
//  Created by Callum Macrae on 15/06/2021.
//

#include <iostream>
#include <string>

#include "calculate.hpp"

float calculate(const std::string& mathString) {
    std::wstring::size_type firstCharPos = mathString.find_first_not_of(' ');
    std::wstring::size_type lastCharPos = mathString.find_last_not_of(' ');
    
    if (mathString[firstCharPos] == '(' && mathString[lastCharPos] == ')') {
        return calculate(mathString.substr(firstCharPos + 1, lastCharPos - firstCharPos - 1));
    }
    
    int bracketsDeep = 0;
    for (int i = 0; i < mathString.size(); i++) {
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
    for (int i = 0; i < mathString.size(); i++) {
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
    
    return std::stof(mathString);
}
