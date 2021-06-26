//
//  calculate.cpp
//  calculator
//
//  Created by Callum Macrae on 15/06/2021.
//

#include <iostream>
#include <math.h>
#include <optional>
#include <string>

#include "calculate.hpp"

using PairOfFloats = std::pair<float, float>;
using OptionalPair = std::optional<PairOfFloats>;

static OptionalPair findOperation(const std::string_view &mathString,
                                  const char &operation) {
  int bracketsDeep = 0;
  for (int i = (int)mathString.size() - 1; i >= 0; i--) {
    if (mathString[i] == '(') {
      bracketsDeep++;
    } else if (mathString[i] == ')') {
      bracketsDeep--;
    }

    if (bracketsDeep == 0 && mathString[i] == operation) {
      float left = calculate(mathString.substr(0, i));
      float right = calculate(mathString.substr(i + 1));

      // @todo how does this work with memory and stuff
      return std::pair(left, right);
    }
  }

  return {};
}

float calculate(const std::string_view &mathString) {
  std::size_t firstCharPos = mathString.find_first_not_of(' ');
  std::size_t lastCharPos = mathString.find_last_not_of(' ');
  char firstChar = mathString[firstCharPos];

  if ((firstChar == '(' || (firstChar >= 'a' && firstChar <= 'z')) &&
      mathString[lastCharPos] == ')') {
    std::size_t firstBracketPos =
        firstChar == '(' ? firstCharPos : mathString.find_first_of('(');
    float innerResult = calculate(
        mathString.substr(firstBracketPos + 1, lastCharPos - firstCharPos - 1));

    if (firstChar == '(') {
      return innerResult;
    }

    std::string_view function =
        mathString.substr(firstCharPos, firstBracketPos - firstCharPos);

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

  OptionalPair lastPlus = findOperation(mathString, '+');
  if (lastPlus.has_value()) {
    PairOfFloats val = lastPlus.value();
    return val.first + val.second;
  }

  OptionalPair lastMinus = findOperation(mathString, '-');
  if (lastMinus.has_value()) {
    PairOfFloats val = lastMinus.value();
    return val.first - val.second;
  }

  OptionalPair lastMultiply = findOperation(mathString, '*');
  if (lastMultiply.has_value()) {
    PairOfFloats val = lastMultiply.value();
    return val.first * val.second;
  }

  OptionalPair lastDivide = findOperation(mathString, '/');
  if (lastDivide.has_value()) {
    PairOfFloats val = lastDivide.value();
    return val.first / val.second;
  }

  OptionalPair lastPow = findOperation(mathString, '^');
  if (lastPow.has_value()) {
    PairOfFloats val = lastPow.value();
    return pow(val.first, val.second);
  }

  return std::stof(std::string(mathString));
}
