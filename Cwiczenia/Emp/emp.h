#ifndef EMP_H_
#define EMP_H_

#include<iostream>
#include<string>

using std::string;

class abstr_emp{
private:
string fname;
string lname;
string job;
public:
  abstr_emp();
  abstr_emp(const string &fn, const string &ln, const string &j);
  virtual void ShowAll() const;
  virtual void SetAll();
  friend std::ostream & operator<<(std::ostream &os,const abstr_emp & e);
  virtual ~abstr_emp() = 0;
};

class employee : public abstr_emp{
public:
  employee(){}
  employee(const string &fn, const string &ln, const string &j):
  abstr_emp(fn,ln,j){}
  virtual void SetAll();
  virtual void ShowAll() const;
};

class manager : virtual public abstr_emp{
private:
  int inchargeof;
protected:
  int InChargeOf() const{return inchargeof;}
  int & InChargeOf() {return inchargeof;}
public:
  manager(){}
  manager(const string &fn, const string &ln, const string &j,int ico = 0):
  abstr_emp(fn,ln,j),inchargeof(ico){}
  manager(const abstr_emp & e, int ico):abstr_emp(e),inchargeof(ico){}
  manager(const manager & m):abstr_emp(m),inchargeof(m.inchargeof){}
  void SetIco(){std::cout<<"Podaj inchargeof: ";std::cin>>inchargeof;}
  virtual void SetAll();
  virtual void ShowAll() const;
};

class fink : virtual public abstr_emp{
private:
  string reportsto;
protected:
  const string ReportsTo() const{return reportsto;}
  string & ReportsTo(){return reportsto;}
public:
  fink(){}
  fink(const string &fn, const string &ln, const string &j,const string & rpo)
  :abstr_emp(fn,ln,j),reportsto(rpo){}
  fink(const abstr_emp & e,const string &rpo)
  :abstr_emp(e),reportsto(rpo){}
  fink(const fink & f)
  :abstr_emp(f),reportsto(f.reportsto){}
  void SetRpo(){std::cout<<"Podaj reportsTo: ";std::cin>>reportsto;}
  virtual void SetAll();
  virtual void ShowAll() const;
};

class highfink : public fink, public manager{
public:
  highfink():abstr_emp(),fink(),manager(){}
  highfink(const string &fn, const string &ln, const string &j,
    const string & rpo, int ico):
    abstr_emp(fn,ln,j),fink(fn,ln,j,rpo),manager(fn,ln,j,ico){}
  highfink(const fink & f,int ico):
  abstr_emp(f),fink(f),manager(f,ico){}
  highfink(const manager & m,const string & rpo):
  abstr_emp(m),fink(m,rpo),manager(m){}
  highfink(const highfink & h):
  abstr_emp(h),fink(h),manager(h){}
  virtual void SetAll();
  virtual void ShowAll() const;
};


#endif
