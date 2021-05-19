#include<bits/stdc++.h>
using namespace std;

const double EPS=1e-10;
struct Point{
  double x,y;
  Point(){}
  Point(double x,double y):x(x),y(y){}
  Point operator+(Point p){ return Point(x+p.x,y+p.y); }
  Point operator-(Point p){ return Point(x-p.x,y-p.y); }
  Point operator*(double k){ return Point(x*k,y*k); }
  Point operator/(double k){ return Point(x/k,y/k); }
  Point &operator+=(Point p){ x+=p.x;y+=p.y; return *this; }
  Point &operator-=(Point p){ x-=p.x;y-=p.y; return *this; }
  Point &operator*=(double k){ x*=k;y*=k; return *this; }
  Point &operator/=(double k){ x/=k;y/=k; return *this; }
  Point operator-() const { return Point(-x,-y); }

  bool operator==(const Point &p) const { return (fabs(x-p.x)<EPS)&&(fabs(x-p.y)<EPS); }
  bool operator<(const Point &p) const { return x==p.x?y<p.y:x<p.x; }
  double euclid(){ return sqrt(x*x+y*y); }
  friend istream &operator>>(istream &is,Point &p) { is>>p.x>>p.y; return is;}
  friend ostream &operator<<(ostream &os,Point &p) { os<<p.x<<' '<<p.y; return os;}
};

bool comp_x(Point a,Point b){ return a.x==b.x?a.y<b.y:a.x<b.x; }
bool comp_y(Point a,Point b){ return a.y==b.y?a.x<b.x:a.y<b.y; }
double cross(Point p1,Point p2){ return p1.x*p2.y-p1.y*p2.x; }

Point rotCW(Point origin,Point p,double rad){
  p.x-=origin.x;
  p.y-=origin.y;
  Point res=Point(p.x*cosl(rad)+p.x*sinl(rad),-p.y*sinl(rad)+p.y*cosl(rad));
  res.x+=origin.x;
  res.y+=origin.y;
  return res;
}

Point rotCCW(Point origin,Point p,double rad){
  p.x-=origin.x;
  p.y-=origin.y;
  Point res=Point(p.x*cos(rad)-p.y*sin(rad),p.x*sin(rad)+p.y*cos(rad));
  res.x+=origin.x;
  res.y+=origin.y;
  return res;
}

bool equal(double a,double b){ return fabs(a-b)<EPS; }

// 線分abをm:nに内分する点
Point internalDivision(Point a,Point b,double m,double n){
  if(equal(m+n,0.0)) return Point(0,0);
  return Point((a.x*n+b.x*m)/(m+n),(a.y*n+b.y*m)/(m+n));
}

// 線分abをm:nに外分する点
Point externalDivision(Point a,Point b,double m,double n){
  if(equal(m-n,0.0)) return Point(0,0);
  return Point((-n*a.x+m*b.x)/(m-n),(-n*a.y+m*b.y)/(m-n));
}

int main(){

}