/**  ~*BISMILLAHIR RAHMANIR RAHIM*~  **/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second

typedef long long intl;
typedef pair<int, int> pii;

const intl MX = 1123456;
int n, a[MX], b[MX];

int main()
{
  ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int cases;
  cin>>cases;
  while( cases-- )
  {
    cin>>n;
    for(int i=0; i<n; i++) cin>>a[i];
    for(int i=0; i<n; i++) cin>>b[i];

    sort(a, a+n);
    sort(b, b+n);
    intl sm = 0;
    for(int i=0; i<n; i++)
    {
      sm += (a[i]*b[i]);
    }
    cout<<sm<<endl;
  }
  return 0;
}
