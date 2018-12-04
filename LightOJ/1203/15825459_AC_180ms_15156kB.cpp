/* BISMILLAHIR RAHMANIR RAHIM */
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
typedef long long intl;
typedef pair<int, int> pii;

const double PI = acos(-1.0);

struct point {
  intl x, y;
  point() { x = y = 0; }
  point( intl _x, intl _y ) : x (_x), y(_y) { }
  bool operator == ( point o ) const { return x == o.x && y == o.y; }
  bool operator < ( point o ) const { return x != o.x ? x < o.x : y < o.y; }
  double normal() { return sqrt(x * x + y * y); }
};

intl dotp( point a, point b ) {
  return (a.x * b.x + a.y * b.y);
}

bool cw( const point& a, const point& b, const point& c ) {
  return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x) < 0;
}

vector<point> convexHull( vector<point> p ) {
  int n = p.size(), j = 0;
  if( n <= 1 ) return p;
  sort(p.begin(), p.end());
  vector<point> q(n * 2);
  for(int i = 0; i < n; q[j++] = p[i++])
    for(; j >= 2 && !cw( q[j - 2], q[j - 1], p[i] ); --j);

  for(int i = n - 2, t = j; i >= 0; q[j++] = p[i--])
    for(; j > t && !cw( q[j - 2], q[j - 1], p[i] ); --j);

  q.resize(j - 1 - (q[0] == q[1]));
  return q;
}

double RAD_2_DEG( double theta ) { return (theta * (180.0 / PI)); }

double innerAngle( point a, point b, point c ) {
  point ab = point(a.x - b.x, a.y - b.y);
  point cb = point(c.x - b.x, c.y - b.y);
  double angle = acos( (dotp( ab, cb ) * 1.0) / (ab.normal() * cb.normal()) );
  angle = RAD_2_DEG( angle );
  if( angle > 180.0 ) angle = 360.0 - angle;
  return angle;
}

int n;
map<pii, int> mp;

int main() {
  int cases, caseno = 0;
  scanf("%d", &cases);
  while( cases-- ) {
    scanf("%d", &n);
    vector<point> p;
    mp.clear();
    for(int i = 0, x, y; i < n; i++) {
      scanf("%d %d", &x, &y);
      if( mp.find(pii(x, y)) == mp.end() ) {
        p.push_back(point(x, y));
        mp[pii(x, y)] = 1;
      }
    }
    n = p.size();
    printf("Case %d: ", ++caseno);
    if( n <= 2 ) {
      printf("0\n");
      continue;
    }
    vector<point> hull = convexHull( p );
    double resA = 181;
    n = hull.size();
    for(int i = 1; i < n - 1; i++)
      resA = min(resA, innerAngle( hull[i - 1], hull[i], hull[i + 1] ));

    resA = min(resA, innerAngle( hull[n - 1], hull[0], hull[1] ));
    resA = min(resA, innerAngle( hull[n - 2], hull[n - 1], hull[0] ));
    printf("%.7lf\n", resA);
    //cout << fixed << setprecision(10) << resA << endl;
  }
  return 0;
}


//  vector<point> p(4);
//  p[0] = {0, 0};
//  p[1] = {3, 0};
//  p[2] = {0, 3};
//  p[3] = {1, 1};
//  vector<point> hull = convexHull( p );
