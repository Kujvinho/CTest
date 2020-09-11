#include "emp.h"

using std::cout;using std::endl;using std::cin;

//abstr_emp
abstr_emp::abstr_emp(){fname = "";lname = "";job = "";}
abstr_emp::abstr_emp(const string &fn, const string &ln, const string &j){
  fname = fn;lname = ln;job = j;
}
void abstr_emp::ShowAll() const{
  cout<<"Imie: "<<fname<<"\nNazwisko: "<<lname<<"\nPraca: "<<job<<endl;
}
void abstr_emp::SetAll(){
  cout<<"Podaj imie: ";
  getline(cin,fname);
  cout<<"Podaj nazwisko: ";
  getline(cin,lname);
  cout<<"Podaj prace:";
  getline(cin,job);
}
abstr_emp::~abstr_emp(){}

//employee
void employee::SetAll(){abstr_emp::SetAll();}
void employee::ShowAll() const{abstr_emp::ShowAll();}

//manager
void manager::SetAll(){
  abstr_emp::SetAll();
  manager::SetIco();
}
void manager::ShowAll() const{
  abstr_emp::ShowAll();
  cout<<"Inchargeof: "<<inchargeof<<endl;
}

//fink
void fink::SetAll(){
  abstr_emp::SetAll();
  fink::SetRpo();
}
void fink::ShowAll() const{
  abstr_emp::ShowAll();
  cout<<"reportsto: "<<reportsto<<endl;
}

//highfink
void highfink::SetAll(){
  abstr_emp::SetAll();
  manager::SetIco();
  fink::SetRpo();
}
void highfink::ShowAll() const{
  abstr_emp::ShowAll();
  cout<<"inchargeof: "<<manager::InChargeOf()<<endl;
  cout<<"reportsto: "<<fink::ReportsTo()<<endl;
}

//friends
std::ostream & operator<<(std::ostream &os,const abstr_emp & e){
  os<<"Imie: "<<e.fname<<" Nazwisko: "<<e.lname<<" Praca: "<<e.job<<endl;
  return os;
}
