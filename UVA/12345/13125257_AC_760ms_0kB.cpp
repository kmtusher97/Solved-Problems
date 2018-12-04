/**  ~*BISMILLAHIR RAHMANIR RAHIM*~  **/

#include <bits/stdc++.h>

using namespace std;

typedef long long intl;

const int MX = 1123456;
int n, Q, a[MX];
bitset<MX> bt;

int main()
{
  scanf("%d %d", &n, &Q);
  for(int i=0; i<n; i++)
  {
    scanf("%d", a+i);
  }
  while( Q-- )
  {
    char ch[3];
    int l, r;
    scanf("%s %d %d", ch, &l, &r);
    if( ch[0]=='Q' )
    {
      int ans = 0;
      for(int i=l; i<r; i++)
      {
        if( bt[a[i]]==0 ) ans++;
        bt[a[i]] = 1;
      }
      printf("%d\n", ans);
      bt = 0;
    }
    else a[l] = r;
  }
  return 0;
}
