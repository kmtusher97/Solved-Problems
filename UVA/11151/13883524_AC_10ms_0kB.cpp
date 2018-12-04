/**  ~*BISMILLAHIR RAHMANIR RAHIM*~  **/

#include <bits/stdc++.h>
using namespace std;

const int MX = 1004;
char s[MX];
int n, ff[MX][MX];

int dp( int l, int r )
{
  if( l>r ) return 0;
  if( l==r ) return 1;
  if( l+1==r )
  {
    if( s[l]==s[r] ) return 2;
    return 1;
  }
  if( ~ff[l][r] ) return ff[l][r];

  if( s[l]==s[r] ) return ff[l][r] = 2 + dp( l+1, r-1 );
  else return ff[l][r] = max( dp( l+1, r ), dp( l, r-1 ) );
}

int main()
{
  int cases;
  scanf("%d", &cases);
  getchar();
  while( cases-- )
  {
    gets(s), n = strlen(s);
    memset(ff, -1, sizeof ff);
    printf("%d\n", dp( 0, n-1 ));
  }
  return 0;
}
