/**  ~*BISMILLAHIR RAHMANIR RAHIM*~  **/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second

typedef long long intl;
typedef pair<int, int> pii;

const int MX = 212;

int main() {
  ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int cases, caseno = 0;
  cin>>cases;
  while( cases-- )
  {
    intl x, res = 0LL, mlt = 5LL;
    cin>>x;
    while( x/mlt )
    {
      res += (x/mlt);
      mlt *= 5LL;
    }
    cout<<res<<endl;
  }
  return 0;
}
