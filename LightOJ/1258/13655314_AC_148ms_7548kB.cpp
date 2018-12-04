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
      while( j>=0 && P[n-i-1]!=P[n-j-1] ) j = FF[j];
      FF[++i] = ++j;
    }
  }
  int customSearch( char* T )
  {
    int N = strlen(T), i, j;
    for(i=0, j=0; i<N; )
    {
      while( j>=0 && T[i]!=T[N-j-1] )
      {
        j = FF[j];
      }
      i++, j++;
      if( j==N ) return N;
    }
    return (2*N-j);
  }
} kmp;


int main()
{
  int cases, caseno = 0;
  scanf("%d", &cases);
  while( cases-- )
  {
    scanf("%s", a);
    kmp.buildPrefixFunc( a );
    int res = kmp.customSearch( a );
    printf("Case %d: %d\n", ++caseno, res);
  }
  return 0;
}
