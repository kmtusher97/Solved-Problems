/**  ~*BISMILLAHIR RAHMANIR RAHIM*~  **/

#include <bits/stdc++.h>

using namespace std;

const int MX = 2002;
int n, m, ff[MX][MX];
char a[MX], b[MX];

int main()
{
  int cases;
  scanf("%d", &cases);
  while( cases-- )
  {
    scanf("%s %s", a, b);
    n = strlen(a), m = strlen(b);
    memset(ff, 0, sizeof ff);
    for(int i=0; i<=max(n, m)+1; i++)
    {
      ff[0][i] = ff[i][0] = i;
    }
    for(int i=1; i<=n; i++)
    {
      for(int j=1; j<=m; j++)
      {
        if( a[i-1]==b[j-1] )
        {
          ff[i][j] = ff[i-1][j-1];
        }
        else
        {
          ff[i][j] = 1 + min( ff[i-1][j], min( ff[i][j-1], ff[i-1][j-1] ) );
        }
      }
    }
    printf("%d\n", ff[n][m]);
  }
  return 0;
}
