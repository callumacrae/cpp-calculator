#define CATCH_CONFIG_MAIN

#include <catch2/catch.hpp>
#include "../src/calculate.hpp"

TEST_CASE("Calculate works") {
  REQUIRE(calculate("1 + 2") == 3);
  REQUIRE(calculate("3 - 2") == 1);
  REQUIRE(calculate("3 * 2") == 6);
  REQUIRE(calculate("10 / 2") == 5);
  REQUIRE(calculate("2 ^ 10") == 1024);

  REQUIRE(calculate("(1)") == 1);
  REQUIRE(calculate("(1 + 2) * 3") == 9);
  REQUIRE(calculate("((4 / 4) + 2) * 3") == 9);

  REQUIRE(calculate("3 / 2") == 1.5f);
  REQUIRE(calculate("3.5 / 2") == 1.75f);

  REQUIRE(calculate("cos(0)") == 1);
  REQUIRE(floorf(calculate("sin(2)") * 1e4) / 1e4 == 0.9092);
  REQUIRE(calculate("round(sin(2)) * 2 + floor(cos(2)) * 3") == -1);

  REQUIRE(calculate("1 + 2 + 3") == 6);
  REQUIRE(calculate("1 * 2 + 3") == 5);
  REQUIRE(calculate("1 + 2 * 3") == 7);
  REQUIRE(calculate("1 * 4 / 2") == 2);

  REQUIRE(calculate("2 ^ 10 / 2") == 512);
  REQUIRE(calculate("2 ^ (10 / 2)") == 32);

  REQUIRE(calculate("12 / 4 * 2") == 6);
  REQUIRE(calculate("1 + 2 - 3 + 4") == 4);

  REQUIRE(calculate("2.5 * 4 + (1 + 2 * 2) / 5 - 3 * 2") == 5);
}
