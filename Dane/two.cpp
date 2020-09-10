#include<iostream>
#include<vector>
#include<algorithm>

int main(){
  std::vector<double> v(3);
  std::cout<<"Podaj trzy wyniki sprintow na 100 metrow:\n";
  for(int i = 0;i<3;++i){
    std::cin>>v[i];
  }
  for(int i = 0;i<v.size();++i){
    std::cout<<i+1<<". wynik: "<<v[i]<<std::endl;
  }
  double srednia=0;
  std::for_each(v.begin(),v.end(),[&](double &a){srednia+=a;});
  srednia/=v.size();
  std::cout<<"Srednia biegow: "<<srednia<<std::endl;
  return 0;
}
