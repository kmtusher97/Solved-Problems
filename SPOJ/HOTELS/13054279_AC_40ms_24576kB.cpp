/**  ~*BISMILLAHIR RAHMANIR RAHIM*~  **/

#include <bits/stdc++.h>

using namespace std;

typedef long long intl;

const int MX = 1123456;
intl n, m, a[MX];

int main()
{
  ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  cin>>n>>m;
  for(int i=1; i<=n; i++)
  {
    cin>>a[i];
  }
  intl sm = 0, mx = 0, p = 1, q = 1;
  while( true )
  {
    if( p>n && q>n ) break;

    if( q<=n )
    {
      sm += a[q++];
    }
    else if( p<=n )
    {
      sm -= a[p++];
    }
    if( sm<=m ) mx = max(mx, sm);
    else
    {
      while( sm>m && p<=n )
      {
        sm -= a[p++];
        if( sm<=m ) mx = max(mx, sm);
      }
    }
  }
  cout<<mx<<endl;
  return 0;
}
