#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define pbk pop_back
#define mk_pr make_pair

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<string> vss;
typedef queue<int> qi;

const int MX = 112345;
const double PI = acos(-1);

struct point {
  double x, y;
  void mid_point( point p, point q ) {
    x = (p.x+q.x)/2.0;
    y = (p.y+q.y)/2.0;
  }
};

struct co_efficient {
  double a, b, c;
  void stright_line_eqn( point p, point q ) {
    a = p.y-q.y, b = q.x-p.x, c = p.x*q.y - q.x*p.y;
  }
  void perpendicular_line_eqn( co_efficient p, point q ) {
    a = p.b, b = -p.a, c = -1*(a*q.x + b*q.y);
  }
};

point point_of_intersection( co_efficient p, co_efficient q ) {
  point xx;
  xx.x = (p.b*q.c - q.b*p.c) / (p.a*q.b - q.a*p.b);
  xx.y = (q.a*p.c - p.a*q.c) / (p.a*q.b - q.a*p.b);
  return xx;
}

double euclead_distance( point p, point q ) {
  return sqrt( (p.x-q.x)*(p.x-q.x) + (p.y-q.y)*(p.y-q.y) );
}

int main() {
  point p[6];
  co_efficient coeff[5];
  while( scanf("%lf%lf%lf%lf%lf%lf", &p[0].x, &p[0].y, &p[1].x, &p[1].y, &p[2].x, &p[2].y) == 6 ) {
    coeff[0].stright_line_eqn( p[0], p[1] );
    coeff[1].stright_line_eqn( p[0], p[2] );
    
    p[4].mid_point( p[0], p[1] );
    p[5].mid_point( p[0], p[2] );
    
    coeff[2].perpendicular_line_eqn( coeff[0], p[4] );
    coeff[3].perpendicular_line_eqn( coeff[1], p[5] );
    
    p[3] = point_of_intersection( coeff[2], coeff[3] );
    double r = euclead_distance( p[0], p[3] );
    
    printf("%.2lf\n", 2*PI*r);
  }
  return 0;
}
