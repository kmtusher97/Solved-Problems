/**  ~*BISMILLAHIR RAHMANIR RAHIM*~  **/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second

typedef long long intl;
typedef pair<double, double> point;

const double EPS = 1e-9;

struct vctr
{
  double x, y;
  vctr() { x = y = 0.0; }
  vctr( double _x, double _y ) : x(_x), y(_y) { }
  bool operator == ( vctr p ) const
  {
    return ( (fabs(x - p.x)<EPS) && (fabs(y - p.y)<EPS) );
  }
};

vctr operator + ( const vctr& a, const vctr& b ) { return vctr( a.x+b.x, a.y+b.y ); }
vctr operator - ( const vctr& a, const vctr& b ) { return vctr( a.x-b.x, a.y-b.y ); }
vctr operator * ( const vctr& a, double s ) { return vctr( a.x*s, a.y*s ); }
vctr operator * ( double s, const vctr& a ) { return vctr( a.x*s, a.y*s ); }
vctr operator / ( const vctr& a, double s ) { return vctr( a.x/s, a.y/s ); }
vctr operator / ( double s, const vctr& a ) { return vctr( a.x/s, a.y/s ); }

double norm( vctr a ) { return sqrt( a.x*a.x + a.y*a.y); }
double dotp( vctr a, vctr b ) { return ( a.x*b.x + a.y*b.y ); }
double angle_in( vctr a, vctr b ) { return acos( dotp(a, b)/(norm(a)*norm(b)) ); }
double crossp_vlu( vctr a, vctr b ) { return norm(a)*norm(b)*sin( angle_in(a, b) ); }

map< point, int > mp;

int main()
{
  ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int n, cases, caseno = 0;
  cin>>cases;
  while( cases-- )
  {
    cin>>n;
    vector<vctr> P;
    for(int i=0; i<n; i++)
    {
      point p;
      cin>>p.F>>p.S;
      if( mp.find(p)==mp.end() )
      {
        mp[p] = 1;
        P.push_back( vctr(p.F, p.S) );
      }
    }

    int mx = 1;
    for(vctr i : P)
    {
      for(vctr j : P)
      {
        int cnt = 2;
        if( i==j ) continue;
        for(vctr k : P)
        {
          if( k==i || k==j ) continue;
          if( fabs( crossp_vlu( j-i, k-i ) )<EPS ) cnt++;
        }
        mx = max(mx, cnt);
      }
    }
    cout<<"Data set #"<<++caseno<<" ";
    if( P.size()==1 ) cout<<"contains a single gnu."<<endl;
    else cout<<"contains "<<P.size()<<" gnus, out of which a maximum of "<<mx<<" are aligned."<<endl;
    mp.clear();
  }
  return 0;
}

