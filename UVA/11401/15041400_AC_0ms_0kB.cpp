/*  ~*BISMILLAHIR RAHMANIR RAHIM*~  */
#include <bits/stdc++.h>
using namespace std;
typedef long long intl;
typedef vector<int> vi;
#define MX_N 1000050
intl ff[MX_N];

int main() {
  ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  for(intl i = 4, p = 1, q = 1, j = 1; i < MX_N; i++) {
    ff[i] = ( ff[i - 1] + p );
    p += q, j++;
    if( j % 2 == 0 ) q++;
  }
  int n;
  while( cin >> n && n >= 3 ) {
    cout << ff[n] << endl;
  }
  return 0;
}
