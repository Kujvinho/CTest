#include<iostream>

static const double CM_TO_CAL = 30.48;
static const double CM_TO_ST = 2.54;

class Height{
private:
  double cm;
  double st;
  double cal;
public:
  Height():cm(0),st(0),cal(0){}
  Height(double a):cm(a),st(a/CM_TO_ST),cal(a/CM_TO_CAL){}
  void Getcm(double a){cm = a; cal = a/CM_TO_CAL; st = a/CM_TO_ST;}
  double ShowCm(){return cm;}
  double ShowSt(){return st;}
  double ShowCal(){return cal;}
};

int main(){
  std::cout<<"Podaj ilosc cm: ";
  double lvd_cm;
  std::cin>>lvd_cm;
  Height result(lvd_cm);
  std::cout<<"Podano "<<result.ShowCm()<<"cm, to :\n"<<result.ShowSt()<<" stop\n"
  <<result.ShowCal()<<"cali.\n";
  return 0;
}
