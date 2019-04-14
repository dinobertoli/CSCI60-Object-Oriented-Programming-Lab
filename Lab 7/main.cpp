#include <iostream>
using namespace std;




int SalCalc(int n)
{
  if(n == 0)
  {
    return 50000;
  }
  else
  {
    return 50000*1.1+5+SalCalc(n-1);
  }
}


int main(){
  cout << SalCalc(10) << endl;
};
