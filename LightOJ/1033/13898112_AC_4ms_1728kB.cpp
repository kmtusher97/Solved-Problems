/*  ~*BISMILLAHIR RAHMANIR RAHIM*~  */

#include <bits/stdc++.h>
using namespace std;

const int MX = 102;
char s[MX];
int n, ff[MX][MX];

int main()
{
  int cases, caseno = 0;
  scanf("%d", &cases);
  while( cases-- )
  {
    scanf("%s", s), n = strlen(s);
    memset(ff, 0, sizeof ff);
    for(int i=0; i<=n; i++) ff[0][i] = ff[i][0] = i;
    for(int i=0; i<n; i++)
    {
      for(int j=0; j<n; j++)
      {
        if( s[i]==s[n-j-1] ) ff[i+1][j+1] = ff[i][j];
        else ff[i+1][j+1] = 1 + min(ff[i+1][j], ff[i][j+1]);
      }
    }
    printf("Case %d: %d\n", ++caseno, ff[n][n]/2);
  }
  return 0;
}
