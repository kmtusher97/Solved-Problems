/**  ~*BISMILLAHIR RAHMANIR RAHIM*~  **/

#include <bits/stdc++.h>

using namespace std;

typedef long long intl;

const int MX = 1123456;
int n, Q, a[MX], cnt[MX];

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
      memset(cnt, 0, sizeof cnt);
      int ans = 0;
      for(int i=l; i<r; i++)
      {
        cnt[a[i]]++;
        if( cnt[a[i]]==1 ) ans++;
      }
      printf("%d\n", ans);
    }
    else a[l] = r;
  }
  return 0;
}
