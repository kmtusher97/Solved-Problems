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

pair<double, double> pp[4], mid, p;

int main() {
  ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  double x1, y1, x2, y2, x3, y3, x4, y4, a1, b1;
  while(cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4) {
      if(x1==x2 && y1==y2) a1 = (x3+x4)- x1, b1 = (y3+y4) - y1;
      else if(x1==x3 && y1==y3) a1 = (x2+x4) - x1, b1 = (y2+y4) - y1;
      else if(x1==x4 && y1==y4) a1 = (x2+x3) - x1, b1 = (y2+y3) - y1;
      else if(x2==x3 && y2==y3) a1 = (x1+x4) - x2, b1 = (y1+y4) - y2;
      else if(x2==x4 && y2==y4) a1 = (x1+x3) - x2, b1 = (y1+y3) - y2;
      else if(x3==x4 && y3==y4) a1 = (x1+x2) - x3, b1 = (y1+y3) - y3;
      cout << fixed << setprecision (3) << a1 << " " << b1 << endl;
  }

  return 0;
}
