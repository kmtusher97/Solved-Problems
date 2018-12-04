/**  ~*BISMILLAHIR RAHMANIR RAHIM*~  **/

#include <bits/stdc++.h>

using namespace std;

const int MX = 100;
int n, prfx[MX];
char p[MX], t[MX];

void KMPProcess( int k )
{
  prfx[0] = -1;
  for(int i=0, j=-1; i<k; )
  {
    while( j>=0 && p[i]!=p[j] ) j = prfx[j];
    prfx[++i] = ++j;
  }
}

bool KMPSearch( int k )
{
  if( n%k ) return false;
  for(int i=0, j=0; i<n; )
  {
    while( j>=0 && t[i]!=p[j] ) j = prfx[j];
    i++, j++;
    if( i%k==0 )
    {
      if( j!=k ) return false;
    }
  }
  return true;
}

int main()
{
  int cases;
  scanf("%d", &cases);
  getchar();
  while( cases-- )
  {
    scanf("%s", t);
    int res = n = strlen(t);
    for(int i=1; i<=n; i++)
    {
      for(int j=0; j<=i; j++)
      {
        if( j==i ) p[j] = '\0';
        else p[j] = t[j];
      }
      KMPProcess( i );
      if( KMPSearch( i ) )
      {
        res = i;
        break;
      }
    }
    printf("%d\n", res);
    if( cases ) printf("\n");
  }
  return 0;
}
