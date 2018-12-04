/*  ~*BISMILLAHIR RAHMANIR RAHIM*~  */

#include <bits/stdc++.h>
using namespace std;

const int MX = 1000006;
int n, lps[MX];
char a[MX];

int main()
{
  int cases, caseno = 0;
  scanf("%d", &cases);
  while( cases-- )
  {
    scanf("%s", a), n = strlen(a);
    lps[0] = -1;
    int i, j;
    for(i=0, j=-1; i<n; )
    {
      while( j>=0 && a[n-i-1]!=a[n-j-1] ) j = lps[j];
      lps[++i] = ++j;
    }
    for(i=0, j=0; i<n; )
    {
      while( j>=0 && a[i]!=a[n-j-1] ) j = lps[j];
      i++, j++;
      if( j==n ) break;
    }
    printf("Case %d: %d\n", ++caseno, 2*n-j);
  }
  return 0;
}
