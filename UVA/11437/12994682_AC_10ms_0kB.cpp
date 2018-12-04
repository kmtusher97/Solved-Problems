/**  ~*BISMILLAHIR RAHMANIR RAHIM*~  **/

#include <bits/stdc++.h>

using namespace std;

typedef long long intl;

const int MX = 11234567;

struct vctr
{
  double x, y;
  vctr() { x = y = 0.0; }
  vctr( double _x, double _y ) : x(_x), y(_y) { }
};

vctr operator + ( const vctr& a, const vctr& b ) { return vctr( a.x+b.x, a.y+b.y ); }
vctr operator - ( const vctr& a, const vctr& b ) { return vctr( a.x-b.x, a.y-b.y ); }
vctr operator * ( const vctr& a, double s ) { return vctr( s*a.x, s*a.y ); }
vctr operator * ( double s, const vctr& a ) { return vctr( s*a.x, s*a.y ); }
vctr operator / ( const vctr& a, double s ) { return vctr( a.x/s, a.y/s ); }
vctr operator / ( double s, const vctr& a ) { return vctr( a.x/s, a.y/s ); }

double norm_sq( vctr a ) { return ( a.x*a.x + a.y*a.y ); }
double norm( vctr a ) { return sqrt( a.x*a.x + a.y*a.y ); }
double dotp( vctr a, vctr b ) { return ( a.x*b.x + a.y*b.y ); }
double crossp( vctr a, vctr b ) { return ( a.x*b.y - b.x*a.y ); }
double angle_in( vctr a, vctr b ) { return acos( dotp( a, b ) / ( norm(a) * norm(b) ) ); }
double crossp_vlu( vctr a, vctr b ) { return ( norm(a)*norm(b)*sin( angle_in(a, b) ) ); }
void inner_Div_point( vctr a, vctr b, vctr& p, double m, double n ) { p = (m*b + n*a)/(m+n); }
void outer_Div_point( vctr a, vctr b, vctr& p, double m, double n ) { p = (m*b - n*a)/(m-n); }

struct line
{
  vctr a, ab;
  line() { a = ab = vctr(0, 0); }
  line( vctr _a, vctr _ab ) : a(_a), ab(_ab) { }
};

line toLine( vctr& a, vctr& b ) { return line( a, b-a ); }
void intersect_Point_sg( line A, line B, vctr& p )
{
  double l = A.ab.x*(B.a.y-A.a.y) - A.ab.y*(B.a.x - A.a.x);
  l /= ( B.ab.x*A.ab.y - B.ab.y*A.ab.x );
  p = B.a + l*(B.ab);
}

int main()
{
  ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int cases;
  cin>>cases;
  while( cases-- )
  {
    double ar[7];
    for(int i=1; i<=6; i++) cin>>ar[i];
    vctr A( ar[1], ar[2] ), B( ar[3], ar[4] ), C( ar[5], ar[6] ), D, E, F;
    inner_Div_point( B, C, D, 1, 2 );
    inner_Div_point( C, A, E, 1, 2 );
    inner_Div_point( A, B, F, 1, 2 );

    line AD, CF, BE;
    vctr P, Q, R;
    AD = toLine( A, D );
    BE = toLine( B, E );
    CF = toLine( C, F );

    intersect_Point_sg( AD, BE, P );
    intersect_Point_sg( BE, CF, Q );
    intersect_Point_sg( CF, AD, R );

    double area = 0.5 * crossp_vlu( Q-P, R-P );
    intl AREA = area*10;
    if( AREA%10 >= 5 ) (AREA /= 10)++;
    else AREA /= 10;
    cout<<AREA<<endl;
  }
  return 0;
}

