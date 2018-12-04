/**  ~*BISMILLAHIR RAHMANIR RAHIM*~  **/

#include <bits/stdc++.h>
using namespace std;

#define MX_N 1123

typedef long long intl;

intl n, a[MX_N][2], ff[MX_N][3*MX_N];

int main() {
  ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int cases;
  cin>>cases;
  while( cases-- )
  {
      cin>>n;
      for(int i=1; i<=n; i++)
      {
          cin>>a[i][0]>>a[i][1];
      }
      memset(ff, 0, sizeof ff);
      for(int i=1; i<=n; i++)
      {
          for(int j=1; j<=35; j++)
          {
              intl p = 0;
              if( j>=a[i][1] ) p = a[i][0] + ff[i-1][j-a[i][1]];
              ff[i][j] = max( p, ff[i-1][j] );
          }
      }
      intl Q, res = 0;
      cin>>Q;
      while( Q-- )
      {
          int x; cin>>x;
          res += ff[n][x];
      }
      cout<<res<<endl;
  }
  return 0;
}
