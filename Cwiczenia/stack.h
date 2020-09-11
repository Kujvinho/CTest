#ifndef STACK_H_
#define STACK_H_

#include<iostream>

typedef unsigned long Item;

class Stack{
private:
  enum {MAX = 10};
  Item * pitems;
  int size;
  int top;
public:
  Stack(int n = MAX);
  Stack(const Stack &st);
  ~Stack();
  bool isempty() const;
  bool isfull() const;
  bool push(const Item & item);
  bool pop(Item & item);
  void ShowStock() const;
  Stack & operator=(const Stack & st);
};

Stack::Stack(int n){
  if(n>0)
    pitems = new Item[n];
  size = n;
  top = 0;
}

Stack::~Stack(){
  delete [] pitems;
}

Stack::Stack(const Stack & st){
    size = st.size;
    top = st.top;
    pitems = new Item[size];
    for(int i=0;i<size;i++){
      pitems[i] = st.pitems[i];
    }
}

bool Stack::isfull() const{
  return top==size ? true  : false;
}

bool Stack::isempty() const{
  return top==0 ? true : false;
}

bool Stack::push(const Item & item){
  if(isfull()){
    std::cout<<"Stos jest pelen\n";
    return false;
  }
  pitems[top++] = item;
  return true;
}

bool Stack::pop(Item & item){
  if(isempty()){
    std::cout<<"Stos jest pusty.\n";
    return false;
  }
  top--;
  item = pitems[top];
  pitems[top] = 0;
  return true;
}

Stack & Stack::operator=(const Stack & st){
  if(this==&st)
    return *this;
  this->top = st.top;
  this->size = st.size;
  delete [] this->pitems;
  this->pitems = new Item[this->size];
  for(int i=0;i<this->size;i++){
    this->pitems[i] = st.pitems[i];
  }
  return *this;
}

void Stack::ShowStock() const {
  std::cout<<"Stos o rozmiarze: "<<size<<std::endl<<"Przechowuje "<<top<<"Elementow.\n";
  for(int i = 0;i<top;i++){
    std::cout<<pitems[i]<<" ";
  }
  std::cout<<std::endl;
}













#endif
