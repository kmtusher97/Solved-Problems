#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second

typedef long long intl;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int MX = 12345678;

int main() {
  int cases;
  scanf("%d", &cases);
  while( cases-- ) {
    intl n, mlt = 5LL, ans = 0LL;
    scanf("%lld", &n);
    while( n/mlt>0 ) {
      ans += (n/mlt);
      mlt *= 5LL;
    }
    printf("%lld\n", ans);
  }
  return 0;
}
