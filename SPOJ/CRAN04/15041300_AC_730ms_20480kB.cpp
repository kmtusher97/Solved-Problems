/*  ~*BISMILLAHIR RAHMANIR RAHIM*~  */
#include <bits/stdc++.h>
using namespace std;
typedef long long intl;
#define MX_N 1123456
int n, k;
int a[MX_N];
string S;

int main() {
  ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int cases, caseno = 0;
  cin >> cases;
  while( cases-- ) {
    cin >> n >> k >> S;
    for(int i = 0; S[i]; i++)
      a[i + 1] = S[i] - '0';

    for(int i = 1; i <= n; i++)
      a[i] += a[i - 1];

    intl res = 0LL;
    for(int i = 1; i <= n; i++) {
      int lo = i, hi = n;
      while( lo <= hi ) {
        int mid = lo + (hi - lo) / 2;
        if( a[mid] - a[i - 1] >= k ) hi = mid - 1;
        else lo = mid + 1;
      }
      int L = lo;
      hi = n;
      while( lo <= hi ) {
        int mid = lo + (hi - lo) / 2;
        if( a[mid] - a[i - 1] > k ) hi = mid - 1;
        else lo = mid + 1;
      }
      res += (lo - L);
    }
    cout << res << endl;
  }
  return 0;
}