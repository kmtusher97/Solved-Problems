/**  ~*BISMILLAHIR RAHMANIR RAHIM*~  **/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second

typedef long long intl;
typedef pair<int, int> pii;

const intl MX = 112345;
const intl mod = 1000000007LL;
intl a, b, c, n;

int main()
{
  ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int cases;
  cin>>cases;
  while( cases-- )
  {
    cin>>a>>b>>c>>n;
    priority_queue<intl> lft, rgt;
    lft.push(1LL);
    intl sm = 1LL;
    for(intl i=2; i<=n; i++)
    {
      intl median = lft.top(), ff;
      ff = ( (((a%mod) * (median%mod))%mod) + (((b%mod) * (i%mod))%mod) + (c%mod) ) % mod;
      sm += ff;
      if( lft.size()>rgt.size() )
      {
        rgt.push(-ff);
      }
      else
      {
        lft.push(ff);
      }

      if( !lft.empty() && !rgt.empty() )
      {
        while( lft.top()>-rgt.top() )
        {
          intl tmp = -rgt.top(); rgt.pop();
          rgt.push(-lft.top()), lft.pop();
          lft.push(tmp);
        }
      }
    }
    cout<<sm<<endl;
  }
  return 0;
}
