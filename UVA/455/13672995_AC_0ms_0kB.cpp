/**  ~*BISMILLAHIR RAHMANIR RAHIM*~  **/

#include <bits/stdc++.h>

using namespace std;

const int MX = 200;
int n, prfx[MX];
string p;

void KMPProcess()
{
  prfx[0] = -1;
  for(int i=0, j=-1; i<n; )
  {
    while( j>=0 && p[i]!=p[j] ) j = prfx[j];
    prfx[++i] = ++j;
  }
}

int main()
{
  int cases;
  scanf("%d", &cases);
  getchar();
  while( cases-- )
  {
    cin>>p;
    p += p;
    n = p.length();
    KMPProcess();
    int res = n-prfx[n];
    printf("%d\n", res);
    if( cases ) printf("\n");
  }
  return 0;
}
