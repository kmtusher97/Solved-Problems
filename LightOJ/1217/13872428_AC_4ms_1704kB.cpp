/*  ~*BISMILLAHIR RAHMANIR RAHIM*~  */

#include <bits/stdc++.h>

using namespace std;

typedef long long intl;

const int MX = 1123;
intl n, a[MX], ff[MX];

int main()
{
  int cases, caseno = 0;
  scanf("%d", &cases);
  while( cases-- )
  {
    scanf("%lld", &n);
    for(int i=1; i<=n; i++)
    {
      scanf("%lld", a+i);
    }
    intl res = 0;
    ff[1] = 0;
    for(int i=2; i<=n; i++)
    {
      ff[i] = max(a[i]+ff[i-2], ff[i-1]);
    }
    res = ff[n], ff[1] = a[1];
    for(int i=2; i<n; i++)
    {
      ff[i] = max(a[i]+ff[i-2], ff[i-1]);
    }
    res = max(res, ff[n-1]);
    printf("Case %d: %lld\n", ++caseno, res);
  }
  return 0;
}
