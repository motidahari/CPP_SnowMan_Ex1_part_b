 /**
  * Snowman
  * Create a snowman by getting a positive number with 8 digits in the range of 1-4
  * CPP course, Ariel University
  * For more documentation visit: 
  * https://codegolf.stackexchange.com/questions/49671/do-you-want-to-code-a-snowman
  * Created by: Moti Dahari
  * https://github.com/motidahari
  */
 
#include <iostream>
#include <string>
#include <stdexcept>
#include "snowman.hpp"
#include <regex>
#include <algorithm>

using namespace std;
const int ProperNumberOfCharacters = 8;
const int ascii0 = 48;
const int ascii1 = 49;
const int ascii2 = 50;
const int ascii3 = 51;
const int ascii4 = 52;
const int falseNum = -1;
const int trueNum = 1;
enum numbers { num0, num1, num2, num3, num4, num5 ,num6, num7, num8, num9, num10};
enum indexs { Hat0, Mouth1, LeftEye2, RightEye3, LeftArm4, RightArm5 ,Torso6, Base7};
std::array<int,ProperNumberOfCharacters> arr;
const vector<string> Hat = {" _===_\n", "  ___\n .....\n", "   _ \n  /_\\\n", "  ___ \n (_*_)\n"};
const vector<string> Mouth = {",", ".", "_", " "};
const vector<string> LeftEye = {".", "o", "O", "-"};
const vector<string> RightEye = {".", "o", "O", "-"};
const vector<string> LeftArm = {"<", "\\", "/", " "};
const vector<string> RightArm = {">", "/", "\\", " "};
const vector<string> Torso = {" : ", "] [", "> <", "   "};
const vector<string> Base = {" ( : )", " (\" \")", " (___)", " (   )"};

/**
 * getIndex - Gets a char which represents a number (from ascii table) and returns its numeric value less 1
 * For example: if we get "1" we return 0, if we get "2" we return 1..
 * @param: c - char which represents a number
 * @return: index - The value from the ascii table is less than 1
 */

int getIndex(char c){
  if (c >= ascii1 && c <= ascii4){
    return (c-'0')-1; 
  } 
  return falseNum;
}
int getIndex2(char c){
  int ascii = (unsigned char)c;
  if (ascii >= ascii1 && ascii <= ascii4){
    switch (ascii - 1){
    case ascii0:
      return num0;
      break;
    case ascii1:
      return num1;
      break;
    case ascii2:
      return num2;
      break;
    case ascii3:
      return num3;
      break;
    }
  }
  return falseNum;
}


/**
 * checkNegativeNumber - Check whether the number is a negative number or not
 * @param: num - A number
 * @return: 1 - if it is a positive number, -1 if isn't.
 */
int checkNegativeNumber(int num){
  if(num > num0){
    return trueNum;
  }
  throw invalid_argument{"Error: The number is a negative number\n"};
  return falseNum;
}

/**
 * checkSize - Check whether the string size is 8
 * @param: x - A String
 * @return: 1 - If the string length is exactly 8, -1 if isn't.
 */
int checkSize(string const & x){
  std::string msg = "1";
  if(x.size() > ProperNumberOfCharacters){
    msg = "Error: The number of characters is greater than 8\n";
  }else if(x.size() < ProperNumberOfCharacters){
    msg = "Error: The number of characters is less than 8\n";
  }
  if(msg.size() <= 1){
    return trueNum;
  }
  throw invalid_argument{msg};
  return falseNum;
}

/**
 * checkValue - Check if all the characters in the string are in the range of 1-4
 * @param: x - A String
 * @return: 1 - If the string is really in the 1-4 range, -1 if isn't.
 */
int checkValue(string x){
  int result = 1;
  for (size_t i = 0; i < x.size(); i++){
    if (x[i] < ascii1 || x[i] > ascii4){
      result = falseNum;
      break;
    }
  }
  if(result == trueNum){
    return trueNum;
  }
  throw invalid_argument{"Error: The input is not in the 1-4 range\n"};
  return falseNum;
}


/**
 * getRandomNum - Produces a random number in the range 1-4
 * @param: size - The number of characters in the number
 * @return: number - Positive number
 */
int getRandomNum(int size) {//1-4
    int number = num0;
    for (size_t i = num0; i < size; i++){
        number *= num10;
        number += (rand() % num4 + num1);//generate number between 1 and 4:
    }
    return number;
}

/**
 * getRandomNumFrom1To10 - Produces a random number in the range 1-10
 * @param: size - The number of characters in the number
 * @return: number - Positive number
 */
int getRandomNumFrom1To10(int size) {//1-10
    int number = num0;
    for (size_t i = num0; i < size; i++){
        number *= num10;
        number += (rand() % num4 + num1);//generate number between 1 and 10:
    }
    return number;
}

namespace ariel{
  /**
   * snowman - a function that receives a number, checks whether the input is correct, if the input is 
   * incorrect it throws an error, if the input is correct it returns a string representing a snowman 
   * which is constructed by each character in the string
   * @param: num - a number
   * @return: snowMan - a string representing a snowman, empty string and trow error if isn't.
   */

string snowman(int num){
    string str = std::to_string(num);
    std::string result;
    if(checkNegativeNumber(num) != falseNum && checkValue(str) != falseNum && checkSize(str) != falseNum){
      std::string number;
      int i = 0;
      for (auto& e : arr) {
        int index = getIndex(str[i]);
        number += std::to_string(index);
        e = index;
        ++i;
      }
      const int UpLeftArm = (str[num4] == '2') ? num1 : num0;
      const int UpRightArm = (str[num5] == '2') ? num1 : num0;
      result += Hat[arr[num0]];
      result += (UpLeftArm == trueNum) ? LeftArm[arr[num4]] + "(" + LeftEye[arr[num2]] : " (" + LeftEye[arr[num2]];
      result += Mouth[arr[num1]];
      result += (UpRightArm == trueNum) ? RightEye[arr[num3]] + ")" + RightArm[arr[num5]] + "\n" : RightEye[arr[num3]] + ")\n";
      result += (UpLeftArm != trueNum) ? LeftArm[arr[num4]] : " ";
      result += (UpRightArm != trueNum) ? "(" + Torso[arr[num6]] + ")" + RightArm[arr[num5]] + "\n": "(" + Torso[arr[num6]] + ")\n";
      result += Base[arr[num7]] + "\n";
    }
    return result;
  }

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

};


