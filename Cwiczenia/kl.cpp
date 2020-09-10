#include<iostream>

class Move{
private:
  double x;
  double y;
public:
  Move(double a =0,double b=0):x(a),y(b){}
  void Showmove() const {std::cout<<"x: "<<x<<std::endl<<"y: "<<y<<std::endl;}
  Move Add(const Move & m) const{Move res; res.x =m.x + x; res.y = m.y + y; return res;}
  void Reset(double a=0,double b=0){x=a;y=b;}
};

int main(){
  Move m(2,5);
  Move b(3,7);
  Move c;
  c.Showmove();
  c = m.Add(b);
  c.Showmove();
  c.Reset(1,1);
  c.Showmove();
  return 0;
}
