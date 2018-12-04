/** ~*BISMILLAHIR RAHMANIR RAHIM*~ **/

#include <stdio.h>

#define MX 1001

int min( int a, int b )
{
  return (a<b) ? a : b;
}

int n, t[2][MX], T[2][MX], ff[2][MX];

int main()
{
  int cases, caseno = 0, i, j;
  scanf("%d", &cases);
  while( cases-- )
  {
    scanf("%d", &n);
    for(i=0; i<n; i++) scanf("%d", &t[0][i]);
    for(i=0; i<n; i++) scanf("%d", &t[1][i]);
    for(i=0; i<n-1; i++) scanf("%d", &T[0][i]);
    for(i=0; i<n-1; i++) scanf("%d", &T[1][i]);

    ff[0][0] = t[0][0], ff[1][0] = t[1][0];
    for(i=1; i<n; i++)
    {
      for(j=0; j<2; j++)
      {
        ff[j][i] = t[j][i] + min(ff[j][i-1], T[j^1][i-1] + ff[j^1][i-1]);
      }
    }
    printf("Case %d: %d\n", ++caseno, min(ff[0][n-1], ff[1][n-1]));
  }
  return 0;
}
