/**  ~*BISMILLAHIR RAHMANIR RAHIM*~  **/

#include <bits/stdc++.h>
using namespace std;

const int MX = 1004;
char s[MX];
int n, ff[MX][MX];

int main()
{
  int cases;
  scanf("%d", &cases);
  getchar();
  while( cases-- )
  {
    gets(s), n = strlen(s);
    for(int i=0; i<n; i++)
    {
      for(int j=0; j<n; j++)
      {
        if( s[i]==s[n-j-1] ) ff[i+1][j+1] = 1 + ff[i][j];
        else ff[i+1][j+1] = max( ff[i][j+1], ff[i+1][j] );
      }
    }
    printf("%d\n", ff[n][n]);
    memset(ff, 0, sizeof ff);
  }
  return 0;
}
