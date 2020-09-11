#include<iostream>
#include "stack.h"

int main(){
  Stack sztos(2);

  Item it = 150;
  sztos.pop(it);
  sztos.push(it);
  sztos.push(1500);
  sztos.ShowStock();
  std::cout<<std::endl;
  Stack sztos2(sztos);
  sztos2.ShowStock();
  sztos2.pop(it);
  sztos2.push(22);
  sztos2.ShowStock();

  return 0;
}
