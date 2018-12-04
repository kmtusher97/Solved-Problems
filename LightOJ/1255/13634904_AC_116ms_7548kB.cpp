/**  ~*BISMILLAHIR RAHMANIR RAHIM*~  **/

#include <bits/stdc++.h>

using namespace std;

const int MX = 1000007;
int n, m, prfx[MX];
char t[MX], p[MX];

int main()
{
  int cases, caseno = 0;
  scanf("%d", &cases);
  while( cases-- )
  {
    scanf("%s %s", t, p);
    n = strlen(t), m = strlen(p);

    prfx[0] = -1;
    for(int i=0, j=-1; i<m; )
    {
      while( j>=0 && p[i]!=p[j] ) j = prfx[j];
      prfx[++i] = ++j;
    }
    int cnt = 0;
    for(int i=0, j=0; i<n; )
    {
      while( j>=0 && t[i]!=p[j] ) j = prfx[j];
      i++, j++;
      if( j==m ) cnt++;
    }
    printf("Case %d: %d\n", ++caseno, cnt);
  }
  return 0;
}
