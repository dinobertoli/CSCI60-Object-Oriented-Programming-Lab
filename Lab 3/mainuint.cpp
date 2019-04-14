#include <iostream>
#include "biguint.h"
#include <string>

int main(){
  biguint test1 = biguint();
  std::string x = "1234";
  std::string y = "2468";
  biguint test2 = biguint(x);
  biguint test3 = biguint(x);
  biguint test4 = biguint(x);
  biguint test5 = biguint(x);
  biguint test8 = biguint(y);

  test3 += test2;
  size_t temp = 4;
  int fourthDigit = test2[temp];
  int testCompare = test1.compare(test4);
  int testCompare1 = test4.compare(test1);
  int testCompare2 = test4.compare(test5);
  bool testLessThan = test3 < test2;
  bool testGreaterThan = test3 > test2;
  bool testEqualTo = test1 == test4;


  std::cout << fourthDigit << std::endl;
  std::cout << test2;
  std::cout << test3;
  std::cout << testCompare << std::endl;
  std::cout << testCompare1 << std::endl;
  std::cout << testCompare2 << std::endl;
  std::cout << "Should be false: " << testLessThan << std::endl;
  std::cout << "Should be true: " << testGreaterThan << std::endl;
  std::cout << "Should be false: " << testEqualTo << std::endl;

  test3 -= test2;
  std::cout << test3 << std::endl;
  biguint test6 = test8 - test5;
  std::cout << test6 << std::endl;
  test3 += test3;
  std::cout << test3 << std::endl;
  test3 -= test2;
  std::cout << test3 << std::endl;
  std::string strTest = test3.toString();
  std::string strTest1 = "should be same as line before ";
  std:: cout << "toString test: " << strTest << strTest1 << std::endl;
}
