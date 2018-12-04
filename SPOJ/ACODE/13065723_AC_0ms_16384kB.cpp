/**  ~*BISMILLAHIR RAHMANIR RAHIM*~  **/

#include <bits/stdc++.h>

using namespace std;

typedef long long intl;
typedef unsigned long long intu;

const int MX = 51234;
intu ff[MX];

int main()
{
  ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  string s;
  while( cin>>s )
  {
    if( s[0]=='0' ) break;
    int n = s.length();

    for(int i=0; i<=n+5; i++) ff[i] = 0;
    ff[n] = 1;
    for(int i=n-1; i>=0; i--)
    {
      if( s[i]=='0' ) continue;
      ff[i] += ff[i+1];
      if( i+1>=n ) continue;
      int t = 10*(s[i]-'0')+(s[i+1]-'0');
      if( t>0 && t<=26 ) ff[i] += ff[i+2];
    }
    cout<<ff[0]<<endl;
  }
  return 0;
}
