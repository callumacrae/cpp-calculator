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
    if (mathString[mathString.find_first_not_of(' ')] == '(' && mathString[mathString.find_last_not_of(' ')] == ')') {
        unsigned long start = mathString.find('(');
        unsigned long end = mathString.rfind(')');
        
        return calculate(mathString.substr(start + 1, end - start));
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
