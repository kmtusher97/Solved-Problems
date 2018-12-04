/*  ~*BISMILLAHIR RAHMANIR RAHIM*~  */

#include <stdio.h>

#define MX 32

typedef long long intl;

intl nCr[MX][MX];

int main()
{
  for(int i=0; i<MX; i++)
  {
    for(int j=0; j<MX; j++)
    {
      if( i==0 ) nCr[i][j] = 0LL + (!j ? 1LL : 0LL);
      else if( j==0 ) nCr[i][j] = 1LL;
      else nCr[i][j] = nCr[i-1][j-1] + nCr[i-1][j];
    }
  }

  int cases, caseno = 0;
  scanf("%d", &cases);
  while( cases-- )
  {
    int n, k;
    scanf("%d %d", &n, &k);
    printf("Case %d: ", ++caseno);
    if( k>n )
    {
      printf("0\n");
      continue;
    }
    intl res = nCr[n][k] * nCr[n][k];
    for(int i=1; i<=k; i++)
    {
      res *= i;
    }
    printf("%lld\n", res);
  }
  return 0;
}
