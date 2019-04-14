#include "biguint.h"

biguint::biguint(){
  for(std::size_t i = 0; i < CAPACITY; i++){
    data_[i]=0;
  }
}

biguint::biguint(const std::string &a){
  int j = 0;
  char zero = '0';
  int codeZero = zero;
  for(std::size_t i = 1; i < a.size()+1; i++){
    int tempNum = a[a.length() - i];
    int numCode = tempNum - codeZero;
    data_[j]=numCode;
    j++;
  }
  if(j < CAPACITY){
    for(int x = j; x < CAPACITY; x++){
      data_[x]=0;
    }
  }
}

unsigned short biguint::operator [](std::size_t pos) const{
  return biguint::data_[pos];
}

std::ostream& operator <<(std::ostream& out, biguint b){
  for(size_t i = 0; i < biguint::CAPACITY; i++){
    out << b[i] << " ";
  }
  out << std::endl;
  return out;
}

void biguint::operator +=(const biguint & b){
  for(int i = CAPACITY - 1; i >= 0; i--){
    if(data_[i] + b.data_[i] < 10){
      data_[i] = data_[i] + b.data_[i];
    }
    else{
      data_[i - 1] = (data_[i - 1] + 1);
      data_[i] = ((data_[i] + b.data_[i]) - 10);
    }
  }
}

//PROMLEM 2:
// pre: none
// post: returns 1 if this biguint > b
//               0 if this biguint == b
//              -1 if this biguint < b
int biguint::compare(const biguint & b) const{
  int lhsIdx = 0;
  int rhsIdx = 0;
  while(data_[CAPACITY - 1 - lhsIdx] == 0){
    lhsIdx++;
  }
  while(b.data_[CAPACITY - 1 - rhsIdx] == 0){
    rhsIdx++;
  }
  if(lhsIdx > rhsIdx){return -1;}
  else if(lhsIdx < rhsIdx){return 1;}
  else if(lhsIdx == rhsIdx){
    for(int i = 0; i < CAPACITY - lhsIdx; i++){
      if(data_[lhsIdx - i] > b.data_[rhsIdx - i]){return 1; break;}
      if(data_[lhsIdx - i] < b.data_[rhsIdx - i]){return -1; break;}
    }
  }
  return 0;
}

bool operator < (const biguint &a, const biguint &b){
  int temp = a.compare(b);
  if (temp == 1){return false;}
  else if(temp == -1){return true;}
  else if(temp == 0){return false;}
  return false;
};
bool operator <= (const biguint &a, const biguint &b){
  int temp = a.compare(b);
  if (temp == 1){return false;}
  else if(temp == -1){return true;}
  else if(temp == 0){return true;}
  return false;
};
bool operator != (const biguint &a, const biguint &b){
  int temp = a.compare(b);
  if (temp == 1){return true;}
  else if(temp == -1){return true;}
  else if(temp == 0){return false;}
  return false;
};
bool operator == (const biguint &a, const biguint &b){
  int temp = a.compare(b);
  if (temp == 1){return false;}
  else if(temp == -1){return false;}
  else if(temp == 0){return true;}
  return false;
};
bool operator >= (const biguint &a, const biguint &b){
  int temp = a.compare(b);
  if (temp == 1){return true;}
  else if(temp == -1){return false;}
  else if(temp == 0){return true;}
  return false;
};
bool operator > (const biguint &a, const biguint &b){
  int temp = a.compare(b);
  if (temp == 1){return true;}
  else if(temp == -1){return true;}
  else if(temp == 0){return true;}
  return false;
};


//PROBLEM 3
biguint operator - (const biguint &a, const biguint &b){
  std::string x = "0000";
  biguint temp = biguint(x);
  temp += a;
  temp -= b;
  return temp;
}




void biguint::operator -= (const biguint & b){
    for(int i = 0; i < CAPACITY - 1; i++){
      if(data_[i] > b.data_[i]){
        data_[i] = data_[i]-b.data_[i];
      }
      else if(data_[i + 1] != 0){
        data_[i + 1] = (data_[i + 1] - 1);
        data_[i] = (data_[i] + 10);
        data_[i] = data_[i]-b.data_[i];
      }
    }
}

//PROBLEM 4
std::string biguint::toString(){
  std::string temp = "";
  for(int i = CAPACITY - 1; i >= 0; i--){
    temp += std::to_string(data_[i]);
  }
  return temp;
}
