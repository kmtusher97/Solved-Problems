/**  ~*BISMILLAHIR RAHMANIR RAHIM*~  **/

#include <bits/stdc++.h>

using namespace std;

typedef long long intl;

const int MX = 1123456;
const int mod = 100007;
int mark[MX];

intl big_mod( intl b, intl p )
{
  intl x = 1LL;
  while( p>0 )
  {
    if( p&1 ) x = (x*b)%mod;
    b = (b*b)%mod, p /= 2;
  }
  return x;
}

int main()
{
  ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int cases, caseno = 0;
  cin>>cases;
  while( cases-- )
  {
    int n, m, pos = 0;
    cin>>n>>m;
    intl res = 0LL;
    for(int i=1, x; i<=n; i++)
    {
      cin>>x;
      pos = max(pos, mark[x]);
      mark[x] = i;
      intl p = i-pos;
      res = (res + p*(p+1)/2)%mod;
    }
    cout<<"Case "<<++caseno<<": "<<res<<endl;
    memset(mark, 0, sizeof mark);
  }
  return 0;
}
