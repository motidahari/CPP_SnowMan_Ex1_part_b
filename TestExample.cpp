 /**
  * Snowman Tests
  * CPP course, Ariel University
  * For the full documentation visit: https://codegolf.stackexchange.com/q/49671/12019        
  * 
  * Created by: Moti Dahari
  * https://github.com/motidahari
  */
#include "doctest.h"
#include "snowman.hpp"
#include <string>
#include <algorithm>

using namespace ariel;
using namespace std;

/**
 * Returns the input string without the whitespace characters: space, newline and tab.
 * Requires std=c++2a.
 */
  string nospaces(string str){
    str.erase(remove(str.begin(), str.end(), ' '), str.end());
    str.erase(remove(str.begin(), str.end(), '\t'), str.end());
    str.erase(remove(str.begin(), str.end(), '\n'), str.end());
    str.erase(remove(str.begin(), str.end(), '\r'), str.end());
    return str;
  }

/**
 * This test runs on an array of CorrectNumbers (whose range is  1-4)
 */
TEST_CASE("Check Correct Numbers"){
    int size = sizeof(CorrectNumbers)/sizeof(CorrectNumbers[0]);
  for (size_t i = 0; i < size; i++){
    CHECK(nospaces(snowman(CorrectNumbers[i])) == nospaces(snowMan2[i]));
  }
}

/**
 * This test runs on an array of IncorrectNumbers (whose range is not 1-4)
 */
TEST_CASE("Check Incorrect Numbers"){
  int size = sizeof(IncorrectNumbers)/sizeof(IncorrectNumbers[0]);
  for (size_t i = 0; i < size; i++){
    CHECK_THROWS(snowman(IncorrectNumbers[i]));
  }
}

/**
 * This test runs on an array of NegativeNumbers and check the function snowman
 */
TEST_CASE("Check Negative Numbers"){
  int size = sizeof(NegativeNumbers)/sizeof(NegativeNumbers[0]);
  for (size_t i = 0; i < size; i++){
    CHECK_THROWS(snowman(NegativeNumbers[i]));
  }
}

/**
 * This test runs on an array of smallerThan8Characters and check the function snowman
 */
TEST_CASE("Check smaller Than 8 Characters Numbers"){
  int size = sizeof(smallerThan8Characters)/sizeof(smallerThan8Characters[0]);
  for (size_t i = 0; i < size; i++){
    CHECK_THROWS(snowman(smallerThan8Characters[i]));
  }
}

/**
 * This test runs on an array of biggerThan8Characters and check the function snowman
 */
TEST_CASE("Check bigger Than 8 Characters Numbers"){
  int size = sizeof(biggerThan8Characters)/sizeof(biggerThan8Characters[0]);
  for (size_t i = 0; i < size; i++){
    CHECK_THROWS(snowman(biggerThan8Characters[i]));
  }
}

