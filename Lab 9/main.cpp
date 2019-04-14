#include <iostream>
#include "node.h"
#include "lbiguint.h"

using namespace std;

int main(){

  string myStr = "2965";
  lbiguint mylBig = lbiguint(myStr);

  string myStr2 = "1008908";
  lbiguint mylBig2 = lbiguint(myStr2);

  mylBig = mylBig2;

  int testSize = mylBig.size();
//  cout << testSize << endl;
  //cout<< mylBig[0] <<endl;
  cout << mylBig << endl;

  return 0;
}
