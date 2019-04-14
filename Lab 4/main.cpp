#include "dbiguint.h"
#include <iostream>
using namespace std;
int main(){
  string str = "75";
  string str2 = "155";
  dbiguint defaultConst = dbiguint();
  dbiguint usefulConst = dbiguint(str);
  dbiguint coolBeans = dbiguint(str2);
  int testCompare = usefulConst.compare(coolBeans);
  int testCompare2 = coolBeans.compare(usefulConst);
  int testCompare3 = usefulConst.compare(usefulConst);
  dbiguint testPlus = usefulConst + coolBeans;
  dbiguint testMinus = coolBeans - usefulConst;
  dbiguint testEqual = dbiguint();
  testEqual = testMinus;

cout << "should output -1: " << testCompare << endl;
cout << "should output 1: " << testCompare2 << endl;
cout << "should output 0: " << testCompare3 << endl;
cout << "should output 032: " << testPlus << endl;
cout << "should output 08: " << testMinus << endl;
cout << "should output 08: " << testEqual << endl;


  return 0;
}
