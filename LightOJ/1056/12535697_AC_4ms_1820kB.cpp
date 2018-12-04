/**    ~* BISMILLAHIR RAHMANIR RAHIM *~    **/
#include <bits/stdc++.h>
using namespace std;

#define sc scanf
#define pf printf
#define pb push_back
#define pbk pop_back
#define mk_pr make_pair

typedef long long intl;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<string> vss;
typedef queue<int> qi;

const int MX = 300055;

int main() {
  ///ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int cases, caseno = 0;
  sc("%d", &cases);
  while( cases-- ) {
    int a, b;
    char ch;
    sc("%d %c %d", &a, &ch, &b);
    double r = sqrt(a*a+b*b) / 2.0, theta, s, x;
    theta = 2 * acos( (2*r*r-b*b)/(2*r*r) );
    s = r*theta;
    x = 400/(2.0*a+s);
    pf("Case %d: %.9lf %.9lf\n", ++caseno, x*a, x*b);
  }

  return 0;
}
