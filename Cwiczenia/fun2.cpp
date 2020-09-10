#include<iostream>
#include<cstring>

template<class T>
T maxn(T a[] , int n);

char * maxn(char * a[] , int n);

int main(){
  int tab1[5] {1,4,8,3,7};
  double tab2[6] {2.23,4.23,1.23,2.12,4.03,2.11};
  char * tab3[4] {"cos","ktos","ktos cos","nikt"};
  std::cout<<"Maksymalna wartosc tablicy int: "<<maxn(tab1,5)<<std::endl<<
  "Maksymalna wartosc tablicy double: "<<maxn(tab2,6)<<std::endl;
  std::cout<<"Najdluzsze slowo: "<<maxn(tab3,4)<<std::endl;
  return 0;
}

template<class T>
T maxn(T a[] , int n){
  T max = a[0];
  for(int i =0;i<n;++i){
    if(max < a[i])
      max = a[i];
  }
  return max;
}

char * maxn(char * a[] , int n){
  int len = strlen(a[0]);
  char * word = a[0];
  for(int i =0;i<n;++i){
    if(len < strlen(a[i])){
      len = strlen(a[i]);
      word = a[i];
    }
  }
  return word;
}
