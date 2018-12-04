/*
************************************************
*           * KAMRUL HASAN TUSHER              *
*           * JAHANGIRNAGAR UNIVERSITY         *
*           * CSE-45                           *
************************************************
*/
#include <bits/stdc++.h>

using namespace std;

typedef     long long               ll;
typedef     unsigned long long      ull;
typedef     pair<int, int>          pii;
typedef     pair<ll, ll>            pll;
typedef     pair<double, double>    pdd;
typedef     vector<double>          vd;
typedef     vector<ll>              vl;
typedef     vector<int>             vi;
typedef     vector<pii>             vii;
typedef     vector<pll>             vll;
typedef     vector<char>            vcc;
typedef     vector<string>          vss;
typedef     queue<int>              qi;
typedef     queue<pii>              qii;
typedef     priority_queue<int>     PQ;
typedef     priority_queue<pii>     PQII;

#define     sc                scanf
#define     pf                printf
#define     NL                printf("\n")
#define     pb                push_back
#define     mk_pr             make_pair
#define     NIL               -1
#define     VISITED           1
#define     UNVISITED         0
#define     PI                acos(-1.0)
#define     eps               0.0000001
#define     modulo            1000000007
#define     MX                62345
#define     INF               10000000000

#define     READ              freopen("INPUT.in", "r", stdin)
#define     WRITE             freopen("OUTPUT.out", "w", stdout)
#define     read              freopen("INPUT.txt", "r", stdin)
#define     write             freopen("OUTPUT.txt", "w", stdout)
#define     starr(arr, n, v)  for(int i=0; i<n; i++) arr[i] = v
#define     FasterIO          ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

int dx4[] = { 0, 0, 1, -1 };    ///4 connected
int dy4[] = { -1, 1, 0, 0 };
int dx8[] = { 0, 0, 1, -1, -1, -1, 1, 1 };  /// 8 connected
int dy8[] = { -1, 1, 0, 0, 1, -1, -1, 1 };

ll LCM( ll a, ll b ) { return ( (a*b)/__gcd( a, b) ); }
ll POW( ll b, ll p ) { if( !p ) { return 1; } ll x = POW( b, p/2 ); x*=x; if( p&1 ) { x*=b; } return x; }
ll bigMod( ll b, ll p, ll m ) {  if( !p ) { return 1; } ll x = bigMod( b, p/2, m ); x = (x*x) % m; if( p&1 ) { x = (b*x) % m; } return x;  }
ll inv_mod( ll x ) { return bigMod( x, modulo-2, modulo ); }
//int prnt[500]; int prnt_find( int x ) { if( x == prnt[x] ) return x; return prnt[x] = prnt_find( prnt[x] ); }

///geometry functions
double reg_hexagon_area( double x ) { return ( (3.0 * sqrt(3.0) * x * x) / 2.0 ); }
double slope( double x1, double x2, double y1, double y2 ) { return ( (y1-y2) / (x1-x2) ); }
double oppst_side_of_angle( double a, double b, double angle ) { angle = (PI*angle)/180.0; return sqrt( a*a + b*b - (2*a*b*cos(angle)) ); }
double eucld_dis( double x1, double y1, double x2, double y2 ) { return sqrt( (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) ); }
double trngle_area_hiron( double a, double b, double c ) { double s = (a+b+c)/2.0; return sqrt( s*(s-a)*(s-b)*(s-c) ); }


/*...........................................................................................................................................*/

int main() {
  /// read, write;
  FasterIO
  int n;
  while( cin>>n && n ) {
    vi v;
    for(int i=0, x; i<n; i++) {
      cin>>x;
      if( x>0 ) v.pb(x);
    }
    if( v.size()==0 ) {
      cout<<"0"<<endl;
    }
    else {
      for(int i=0, sz=v.size(); i<sz; i++) {
        cout<<v[i];
        if( i==sz-1 ) cout<<endl;
        else cout<<" ";
      }
    }
  }

  return 0;
}


