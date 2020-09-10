#include<iostream>

double calculate(double,double,double (*)(double,double));
double Add(double a,double b){return a+b;}
double Devide(double a,double b){return a/b;}
double Substract(double a,double b){return a-b;}
double Multiply(double a, double b){return a*b;}

int main(){
  double a,b;
  std::cout<<"Podaj dwie liczby: ";
  std::cin>>a>>b;
  std::cout<<"Wynik dodawania: "<<calculate(a,b,Add)<<std::endl<<"Wynik odejmowania: "
  <<calculate(a,b,Substract)<<std::endl<<"Wynik mnozenia: "<<calculate(a,b,Multiply)
  <<std::endl<<"Wynik dzielenia: "<<calculate(a,b,Devide)<<std::endl;
  return 0;
}

double calculate(double a,double b,double (*c)(double,double)){
  return c(a,b);
}
