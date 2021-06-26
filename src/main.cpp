//
//  main.cpp
//  calculator
//
//  Created by Callum Macrae on 15/06/2021.
//

#include <assert.h>
#include <iostream>
#include <string>

#include "calculate.hpp"

int main(int argc, const char *argv[]) {
  assert(calculate("1 + 2") == 3);
  assert(calculate("3 - 2") == 1);
  assert(calculate("3 * 2") == 6);
  assert(calculate("10 / 2") == 5);
  assert(calculate("2 ^ 10") == 1024);

  assert(calculate("(1)") == 1);
  assert(calculate("(1 + 2) * 3") == 9);
  assert(calculate("((4 / 4) + 2) * 3") == 9);

  assert(calculate("3 / 2") == 1.5f);
  assert(calculate("3.5 / 2") == 1.75f);

  assert(calculate("cos(0)") == 1);
  assert(floorf(calculate("sin(2)") * 1e4) / 1e4 == 0.9092);
  assert(calculate("round(sin(2)) * 2 + floor(cos(2)) * 3") == -1);

  assert(calculate("1 + 2 + 3") == 6);
  assert(calculate("1 * 2 + 3") == 5);
  assert(calculate("1 + 2 * 3") == 7);
  assert(calculate("1 * 4 / 2") == 2);

  assert(calculate("2 ^ 10 / 2") == 512);
  assert(calculate("2 ^ (10 / 2)") == 32);

  assert(calculate("12 / 4 * 2") == 6);
  assert(calculate("1 + 2 - 3 + 4") == 4);

  assert(calculate("2.5 * 4 + (1 + 2 * 2) / 5 - 3 * 2") == 5);

  std::cout << "Welcome 2 calculator, enter query to query:\n\n";

  while (true) {
    std::cout << "> ";
    std::string query;
    std::getline(std::cin, query);

    if (query == "exit" || query == "q") {
      std::cout << "bye" << std::endl;
      break;
    }

    std::cout << calculate(query) << std::endl << std::endl;
  }
}
