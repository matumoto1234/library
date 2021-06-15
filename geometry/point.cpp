#include<bits/stdc++.h>
using namespace std;

const double EPS=1e-10;
struct point{
  double x,y;
  point(){}
  point(double x,double y):x(x),y(y){}
  point operator+(point p){ return point(x+p.x,y+p.y); }
  point operator-(point p){ return point(x-p.x,y-p.y); }
  point operator*(double k){ return point(x*k,y*k); }
  point operator/(double k){ return point(x/k,y/k); }
  point &operator+=(point p){ x+=p.x;y+=p.y; return *this; }
  point &operator-=(point p){ x-=p.x;y-=p.y; return *this; }
  point &operator*=(double k){ x*=k;y*=k; return *this; }
  point &operator/=(double k){ x/=k;y/=k; return *this; }
  point operator-() const { return point(-x,-y); }

  bool operator==(const point &p) const { return (fabs(x-p.x)<EPS)&&(fabs(x-p.y)<EPS); }
  bool operator<(const point &p) const { return x==p.x?y<p.y:x<p.x; }
  double euclid(){ return sqrt(x*x+y*y); }
  friend istream &operator>>(istream &is,point &p) { is>>p.x>>p.y; return is;}
  friend ostream &operator<<(ostream &os,point &p) { os<<p.x<<' '<<p.y; return os;}
};

bool comp_x(point a,point b){ return a.x==b.x?a.y<b.y:a.x<b.x; }
bool comp_y(point a,point b){ return a.y==b.y?a.x<b.x:a.y<b.y; }
double cross(point p1,point p2){ return p1.x*p2.y-p1.y*p2.x; }

point rotCW(point origin,point p,double rad){
  p.x-=origin.x;
  p.y-=origin.y;
  point res=point(p.x*cosl(rad)+p.x*sinl(rad),-p.y*sinl(rad)+p.y*cosl(rad));
  res.x+=origin.x;
  res.y+=origin.y;
  return res;
}

point rotCCW(point origin,point p,double rad){
  p.x-=origin.x;
  p.y-=origin.y;
  point res=point(p.x*cos(rad)-p.y*sin(rad),p.x*sin(rad)+p.y*cos(rad));
  res.x+=origin.x;
  res.y+=origin.y;
  return res;
}

bool equal(double a,double b){ return fabs(a-b)<EPS; }

// 線分abをm:nに内分する点
point internalDivision(point a,point b,double m,double n){
  if(equal(m+n,0.0)) return point(0,0);
  return point((a.x*n+b.x*m)/(m+n),(a.y*n+b.y*m)/(m+n));
}

// 線分abをm:nに外分する点
point externalDivision(point a,point b,double m,double n){
  if(equal(m-n,0.0)) return point(0,0);
  return point((-n*a.x+m*b.x)/(m-n),(-n*a.y+m*b.y)/(m-n));
}

int main(){

}