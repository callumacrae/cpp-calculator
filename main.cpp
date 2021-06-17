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
    float result = calculate("1 - 1 + 1");
    std::cout << result << std::endl;
    
    assert(calculate("1 + 2") == 3);
    assert(calculate("3 - 2") == 1);
    assert(calculate("3 * 2") == 6);
    assert(calculate("10 / 2") == 5);
    
    assert(calculate("(1)") == 1);
    assert(calculate("(1 + 2) * 3") == 9);
    
    assert(calculate("3 / 2") == 1.5f);
    assert(calculate("3.5 / 2") == 1.75f);
    
    assert(calculate("1 + 2 + 3") == 6);
    assert(calculate("1 * 2 + 3") == 5);
    assert(calculate("1 + 2 * 3") == 7);
    assert(calculate("1 * 4 / 2") == 2);

    assert(calculate("12 / 4 * 2") == 6);
    assert(calculate("1 + 2 - 3 + 4") == 4);

    assert(calculate("2.5 * 4 + (1 + 2 * 2) / 5 - 3 * 2") == 5);
}
