/**  ~*BISMILLAHIR RAHMANIR RAHIM*~  **/

#include <bits/stdc++.h>

using namespace std;

typedef long long intl;

const int MX = 1<<16;
int n, b, k, d[20];
intl ff[MX+5][25];
char nm[20];

int main()
{
  int cases, caseno = 0;
  scanf("%d", &cases);
  while( cases-- )
  {
    scanf("%d %d %s", &b, &k, nm);
    n = strlen(nm);
    for(int i=0; i<n; i++)
    {
      if( nm[i]>='0' && nm[i]<='9' ) d[i] = nm[i]-'0';
      else d[i] = nm[i]-55;
    }
    sort(d, d+n);

    memset(ff, 0LL, sizeof ff);
    ff[0][0] = 1LL;
    for(int mask=0; mask<(1<<n); mask++)
    {
      for(int mod=0; mod<k; mod++)
      {
        if( !ff[mask][mod] ) continue;
        for(int i=0; i<n; i++)
        {
          if( mask&(1<<i) ) continue;
          ff[mask|(1<<i)][(mod*b + d[i])%k] += ff[mask][mod];
        }
      }
    }

    printf("Case %d: %lld\n", ++caseno, ff[(1<<n)-1][0]);
  }
  return 0;
}
