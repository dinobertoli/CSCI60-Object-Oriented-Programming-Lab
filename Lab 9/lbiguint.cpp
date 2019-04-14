#include "lbiguint.h"
#include<iostream>
#include <cassert>
#include <sstream>

 lbiguint::lbiguint(){

     head = tail = new node(0, nullptr);
 }
 lbiguint::lbiguint (const std::string & s)
 {
     char c = s[0];
     node * previous;
     node * next;
     for (int i = s.size()-1; i >= 0; --i)
     {
       int toStore = s[i] - '0';
       //std::cout << toStore <<std::endl;
       if(i == s.size()-1){
         head = new node(toStore, nullptr);
         previous = head;
       }
       else{
         next = new node(toStore, nullptr);
         previous -> set_link(next);
         previous = next;
       }
     }
     tail = next;
 }


  lbiguint::~lbiguint(){
    node * next;
    for(node*p = head; p != nullptr; p = p -> link()){
      next = p->link();
      delete p;
      head = next;
    }
  }

  std::size_t lbiguint::size() const{
    size_t temp = 0;
    for(node*p = head; p != nullptr; p = p -> link()){
      temp++;
    }
    return temp;
  }

  node::value_type lbiguint::operator [](std::size_t pos) const{
    size_t counter = 0;
    for(node*p = head; p != nullptr; p = p -> link()){
      if(counter == pos){
        return(p->data());
      }
      counter++;
    }

    return(0);
  }

  std::ostream & operator << (std::ostream & a, const lbiguint & b){
    for(std::size_t i = b.size()-1; i > 0; i--){
      a << b[i] << " ";
    }
    a << b[0];

    return a;
  }

  void lbiguint::operator =(const lbiguint & a){
    node* thisTemp = head;
    node* temp = a.head;
    int counter = 0;
    for(int i = 0; i < a.size(); i++){
      counter++;
      if(i >= this->size()){
        node* tempNode = new node(temp->data(), nullptr);
        thisTemp->set_link(tempNode);
        temp = temp->link();
        thisTemp = thisTemp->link();
        tail = thisTemp;
      }
      else{
        thisTemp->set_data(temp->data());
        if(thisTemp != tail){
          thisTemp = thisTemp->link();
          temp = temp->link();
        }
        else{
          temp = temp->link();
        }
      }

    }
/*
    if(this->size() > a.size()){
      thisTemp = thisTemp -> link();
      node* last = thisTemp;
      std::cout << counter << "," << this->size();
      for(int i = counter; i < this->size() - 1; i++){
        last = thisTemp->link();
        delete *thisTemp;
        thisTemp = last;
      }
    }
    */
    tail = thisTemp;
  }
/*
 unsigned short biguint::operator [](std::size_t pos) const
 {
     assert(pos < CAPACITY);
     return _data[pos];
 }



 int biguint::compare(const biguint & b) const{
     for(std::size_t i =CAPACITY-1; i>=0; --i){
         if(_data[i]>b._data[i])
             return 1;
         else if (_data[i]<b._data[i])
             return -1;

     }
     return 0;
 }



 void biguint::operator += (const biguint & b){
     int carry = 0;
     int next = 0;
     for(std::size_t i=0; i<CAPACITY; ++i){
         next = carry+_data[i]+b._data[i];
         _data[i]=next%10;
        carry=next/10;
     }
 }
 std::string biguint::toStdString() const
 {
     std::stringstream ss;
     ss << *this;
     return ss.str();
 }//We haven't talked about stringstreams; just ignore this, I was being lazy.
 std::ostream & operator << (std::ostream & os, const biguint & b)
 {

     for (int i = biguint::CAPACITY - 1; i >= 0; --i)
         os << b[i];
     return os;
 }

 std::istream & operator >> (std::istream & is, biguint & b)
 {
     std::string s;
     is >> s;
     b = biguint(s);
     return is;


 }

 bool operator <(const biguint& a, const biguint& b){
     return (a.compare(b)==-1);
 }

 bool operator <= (const biguint & b1, const biguint & b2)
 {
     return (b1.compare(b2) <= 0);
 }

 bool operator == (const biguint & b1, const biguint & b2)
 {
     return (b1.compare(b2) == 0);
 }

 bool operator != (const biguint & b1, const biguint & b2)
 {
     return (b1.compare(b2) != 0);
 }
*/
//You do > and >=
