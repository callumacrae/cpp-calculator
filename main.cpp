//
//  main.cpp
//  calculator
//
//  Created by Callum Macrae on 15/06/2021.
//

#include <iostream>
#include <string>
#include <assert.h>

#include "calculate.hpp"

int main(int argc, const char * argv[]) {
    int result = calculate("1 + 2");
    std::cout << result << std::endl;
    
    assert(calculate("1 + 2") == 3);
    assert(calculate("3 - 2") == 1);
    assert(calculate("3 * 2") == 6);
    assert(calculate("10 / 2") == 5);
}
