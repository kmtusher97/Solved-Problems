/**  ~*BISMILLAHIR RAHMANIR RAHIM*~  **/

#include <bits/stdc++.h>

using namespace std;

const int MX = 1000007;
char a[MX], b[MX];

struct KMP
{
  static const int MX1 = 1000007;
  int FF[MX1];

  void buildPrefixFunc( char* P )
  {
    FF[0] = -1;
    for(int i=0, j=-1, n=strlen(P); i<n; )
    {
      while( j>=0 && P[i]!=P[j] ) j = FF[j];
      FF[++i] = ++j;
    }
  }
  int customSearch( char* T, char* P )
  {
    int N = strlen(T), M = strlen(P), i, j;
    for(i=0, j=0; i<N; )
    {
      while( j>=0 && T[i]!=P[j] )
      {
        j = FF[j];
      }
      i++, j++;
      if( j==M ) return N;
    }
    return (N+M-j);
  }
} kmp;


int main()
{
  int cases, caseno = 0;
  scanf("%d", &cases);
  while( cases-- )
  {
    scanf("%s", a);
    int i, j;
    for(i=strlen(a)-1, j=0; i>=0; i--, j++) b[j] = a[i];
    b[j] = '\0';
    kmp.buildPrefixFunc( b );
    int res = kmp.customSearch( a, b );
    printf("Case %d: %d\n", ++caseno, res);
  }
  return 0;
}
