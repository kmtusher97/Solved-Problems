/**  ~*BISMILLAHIR RAHMANIR RAHIM*~  **/

#include <bits/stdc++.h>

using namespace std;

const double PI = acos(-1);
const double EPS = 1e-10;

struct vctr
{
  double x, y;
  vctr() { x = y = 0.0; }
  vctr( double _x, double _y ) : x(_x), y(_y) { }
};

vctr operator + ( const vctr& a, const vctr& b ) { return vctr(a.x+b.x, a.y+b.y); }
vctr operator - ( const vctr& a, const vctr& b ) { return vctr(a.x-b.x, a.y-b.y); }
vctr operator * ( const vctr& a, double s ) { return vctr(a.x*s, a.y*s); }
vctr operator * ( double s, const vctr& a ) { return vctr(a.x*s, a.y*s); }
vctr operator / ( const vctr& a, double s ) { return vctr(a.x/s, a.y/s); }
vctr operator / ( double s, const vctr& a ) { return vctr(a.x/s, a.y/s); }

double dotp( vctr a, vctr b ) { return a.x*b.x + a.y*b.y; }
double crossp( vctr a, vctr b ) { return a.x*b.y - a.y*b.x; }
vctr unit_vector( vctr a ) { return a/sqrt(dotp(a, a)); }
double angle_in( vctr a, vctr b )
{
  return acos( dotp(a, b)/sqrt(dotp(a, a)*dotp(b, b)) );
}
vctr rotate_cw90( vctr a ) { return vctr(a.y, -a.x); }
vctr rotate_ccw90( vctr a ) { return vctr(-a.y, a.x); }
vctr rotate_ccw( vctr a, double theta )
{
  return vctr( a.x*cos(theta)-a.y*sin(theta), a.x*sin(theta)+a.y*cos(theta) );
}
vctr intersectPoint( vctr a, vctr b, vctr c, vctr d )
{
  b = b-a, d = d-c, c = c-a;
  assert( dotp(b, b)>EPS && dotp(d, d)>EPS );
  return a + b*crossp(c, d)/crossp(b, d);
}

void print( vctr p, double r )
{
  double g = p.x, h = p.y, c = g*g+h*h-r*r;
  printf("(x "), g >= 0 ? printf("- ") : printf("+ "), printf("%.3lf)^2 + (y ", fabs(g));
  h >= 0 ? printf("- ") : printf("+ "), printf("%.3lf)^2 = %.3lf^2\n", fabs(h), r);
  printf("x^2 + y^2 "), g >= 0 ? printf("- ") : printf("+ "), printf("%.3lfx ", fabs(2*g));
  h >= 0 ? printf("- ") : printf("+ "), printf("%.3lfy ", fabs(2*h));
  c < 0 ? printf("- ") : printf("+ "), printf("%.3lf = 0\n", fabs(c));
  printf("\n");
}

int main()
{
  //ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  vctr A, B, C, D, E;
  while( cin>>A.x>>A.y>>B.x>>B.y>>C.x>>C.y )
  {
    D = (A+B)/2.0;
    E = (B+C)/2.0;

    vctr DD, EE, M;
    DD = D + rotate_ccw90( B-A );
    EE = E + rotate_ccw90( C-B );

    M = intersectPoint( D, DD, E, EE );
    double r = sqrt( dotp( M-A, M-A ) );
    print( M, r );
  }
  return 0;
}

