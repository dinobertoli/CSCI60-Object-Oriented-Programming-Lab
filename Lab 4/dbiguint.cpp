#include "dbiguint.h"
#include <iostream>

dbiguint::dbiguint(){
  data_ = new unsigned short[1];
  data_[0] = 0;
  capacity_ = 1;
}

dbiguint::dbiguint(const std::string &a){
  data_ = new unsigned short[a.size()];
  capacity_ = a.size();
  int j = 0;
  char zero = '0';
  int codeZero = zero;
  for(std::size_t i = 1; i < a.size()+1; i++){
    int tempNum = a[a.length() - i];
    int numCode = tempNum - codeZero;
    data_[j]=numCode;
    j++;
  }
}


std::size_t dbiguint::size() const{
  return capacity_;
}


unsigned short dbiguint::operator [](std::size_t pos) const{
  if(pos < capacity_){
    return dbiguint::data_[pos];
  }
  else{
    return 0;
  }
}

std::ostream& operator <<(std::ostream &out, const dbiguint &b){
  for(size_t i = 0; i < b.size(); i++){
    out<<b[i]<<" ";
  }
  out << std::endl;
  return out;
}

  void dbiguint::reserve(std::size_t newcapacity_){
    if(newcapacity_ > capacity_){
      unsigned short * tempData_ = new unsigned short[newcapacity_];
      for (size_t i = 0; i < capacity_; i++){
        tempData_[i] = data_[i];
      }
        for(size_t j = capacity_; j < newcapacity_; j++){
          tempData_[j] = 0;
        }
        capacity_ = newcapacity_;
      delete [] data_;
      data_ = tempData_;
      tempData_ = nullptr;
    }
    else if(newcapacity_ < capacity_){
      unsigned short * tempData_1 = new unsigned short[newcapacity_];
      for (size_t i = 0; i < newcapacity_; i++){
        tempData_1[i] = data_[i];
      }
        capacity_ = newcapacity_;
      delete [] data_;
      data_ = tempData_1;
      tempData_1 = nullptr;
    }
  }



void dbiguint::operator +=(const dbiguint & b){
  if(b.size() > capacity_){
    reserve(b.size());
  }
  else{
    reserve(capacity_);
  }
  for(size_t i = 0; i < capacity_; i++){
    if (data_[i] + b.data_[i] > 9){
      data_[i+1] = data_[i+1] + 1;
      int tempHolder = data_[i] + b.data_[i];
      tempHolder = tempHolder%10;
      data_[i] = tempHolder;
    }
    else{
      data_[i] = (data_[i] + b.data_[i]);
    }
    }
}

//problem 2
dbiguint:: ~dbiguint(){
  delete [] data_;//This is the only piece we NEED
    data_ = nullptr;
    capacity_ = 0;
}


//PROMLEM 2:
// pre: none
// post: returns 1 if thisdbiguint > b
//               0 if thisdbiguint == b
//              -1 if thisdbiguint < b
int dbiguint::compare(const dbiguint & b) const{
  int lhsIdx = 0;
  int rhsIdx = 0;
  while(data_[capacity_- 1 - lhsIdx] == 0){
    lhsIdx++;
  }
  while(b.data_[capacity_- 1 - rhsIdx] == 0){
    rhsIdx++;
  }
  if(lhsIdx > rhsIdx){return -1;}
  else if(lhsIdx < rhsIdx){return 1;}
  else if(lhsIdx == rhsIdx){
    for(int i = 0; i < capacity_- lhsIdx; i++){
      if(data_[lhsIdx - i] > b.data_[rhsIdx - i]){return -1; break;}
      if(data_[lhsIdx - i] < b.data_[rhsIdx - i]){return 1; break;}
    }
  }
  return 0;
}

bool operator < (const dbiguint &a, const dbiguint &b){
  int temp = a.compare(b);
  if (temp == 1){return false;}
  else if(temp == -1){return true;}
  else if(temp == 0){return false;}
  return false;
};
bool operator <= (const dbiguint &a, const dbiguint &b){
  int temp = a.compare(b);
  if (temp == 1){return false;}
  else if(temp == -1){return true;}
  else if(temp == 0){return true;}
  return false;
};
bool operator != (const dbiguint &a, const dbiguint &b){
  int temp = a.compare(b);
  if (temp == 1){return true;}
  else if(temp == -1){return true;}
  else if(temp == 0){return false;}
  return false;
};
bool operator == (const dbiguint &a, const dbiguint &b){
  int temp = a.compare(b);
  if (temp == 1){return false;}
  else if(temp == -1){return false;}
  else if(temp == 0){return true;}
  return false;
};
bool operator >= (const dbiguint &a, const dbiguint &b){
  int temp = a.compare(b);
  if (temp == 1){return true;}
  else if(temp == -1){return false;}
  else if(temp == 0){return true;}
  return false;
};
bool operator > (const dbiguint &a, const dbiguint &b){
  int temp = a.compare(b);
  if (temp == 1){return true;}
  else if(temp == -1){return true;}
  else if(temp == 0){return true;}
  return false;
};

dbiguint operator +(const dbiguint &a, const dbiguint &b){
  dbiguint temp = dbiguint();
  temp +=a;
  temp +=b;
  return temp;
}

void dbiguint::operator =(const dbiguint &b){
    unsigned short * tempData_ = new unsigned short[b.capacity_];
    for (size_t i = 0; i < b.capacity_; i++){
      tempData_[i] = b.data_[i];
    }
    capacity_ = b.capacity_;
    delete [] data_;
    data_ = tempData_;
    tempData_ = nullptr;
}
//problem 3
void dbiguint::operator -=(const dbiguint & b){
  for(int i = 0; i < capacity_; i++){
    if(data_[i] >= b[i]){
      data_[i] = data_[i]-b[i];
    }
    else if(data_[i + 1] != 0){
      data_[i + 1] = (data_[i + 1] - 1);
      data_[i] = (data_[i] + 10);
      data_[i] = data_[i]-b[i];
    }
  }
  int removeZeros = 0;
  for(int i = capacity_ - 1; i >= 0; i--){
    if(data_[i] == 0){removeZeros++;}
    else if(data_[i] != 0){break;}
  }
  reserve(capacity_ - removeZeros);
}

dbiguint operator - (const dbiguint &a, const dbiguint &b){
  std::string x = "";

  dbiguint temp = dbiguint(x);
  temp += a;
  temp -= b;




  return temp;
}
