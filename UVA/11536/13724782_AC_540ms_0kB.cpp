/** ~*BISMILLAHIR RAHMANIR RAHIM*~ **/

#include <bits/stdc++.h>

using namespace std;

const int MX = 1123456;
int n, m, k, a[MX], frq[MX];

int main()
{
  a[1] = 1, a[2] = 2, a[3] = 3;
  int cases, caseno = 0;
  scanf("%d", &cases);
  while( cases-- )
  {
    scanf("%d %d %d", &n, &m, &k);
    for(int i=4; i<=n; i++)
    {
      a[i] = (a[i-3]+a[i-2]+a[i-1])%m + 1;
    }
    memset(frq, 0, sizeof frq);
    int res = INT_MAX;
    for(int l=1, r=1, cnt=0; r<=n; r++)
    {
      frq[a[r]]++;
      if( a[r]<=k && frq[a[r]]==1 ) cnt++;
      if( cnt==k )
      {
        res = min(res, r-l+1);
        while( cnt==k )
        {
          frq[a[l]]--;
          if( a[l]<=k && frq[a[l]]==0 ) cnt--;
          l++;
          if( cnt==k )
          {
            res = min(res, r-l+1);
          }
        }
      }
    }
    printf("Case %d: ", ++caseno);
    if( res==INT_MAX ) printf("sequence nai\n");
    else printf("%d\n", res);
  }
  return 0;
}
