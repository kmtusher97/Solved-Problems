/* BISMILLAHIR RAHMANIR RAHIM */

#include <bits/stdc++.h>
using namespace std;

#define FasterIO ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define sc scanf
#define pf printf
#define pb push_back

#define F first
#define S second

typedef long long intl;
typedef unsigned long long intu;
typedef queue<int> qi;
typedef vector<int> vi;
typedef pair<int, int> pii;

#define MX_N 112345

const int MX = 112345;

bool chk( int year ) {
  if (year % 400 == 0) return true;
  else if(year % 100 == 0) return false;
  else if(year % 4 == 0) return true;
  else return false;
}

int main() {
  int cases, caseno = 0;
  sc("%d", &cases);
  while( cases-- ) {
    int d, m, y1, y2;
    sc("%d %d %d %d", &d, &m, &y1, &y2);
    pf("Case %d: ", ++caseno);
    if( d==29 && m==2 ) {
      int cnt = 0;
      for(int i=y1+4; i<=y2; i+=4) {
        if( chk(i) )cnt++;
      }
      pf("%d\n", cnt);
      continue;
    }
    pf("%d\n", y2-y1);
  }
  return 0;
}
