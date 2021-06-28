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
  std::cout << "Welcome 2 calculator, enter query to query:\n\n";

  while (true) {
    std::cout << "> ";
    std::string query;
    std::getline(std::cin, query);

    if (query == "exit" || query == "q") {
      std::cout << "bye\n";
      break;
    }

    try {
      std::cout << calculate(query) << "\n\n";
    } catch (...) {
      std::cout << "?\n\n";
    }
  }
}
