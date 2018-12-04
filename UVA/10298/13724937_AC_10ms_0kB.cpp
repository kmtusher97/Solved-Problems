/** ~*BISMILLAHIR RAHMANIR RAHIM*~ **/

#include <bits/stdc++.h>

using namespace std;

const int MX = 1123456;
int n, lps[MX];
string s;

int main()
{
  ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  while( cin>>s && s[0]!='.' )
  {
    n = s.size(), lps[0] = -1;
    for(int i=0, j=-1; s[i]; )
    {
      while( j>=0 && s[i]!=s[j] ) j = lps[j];
      lps[++i] = ++j;
    }
    int res = n/(n-lps[n]);
    cout<<res<<endl;
  }
  return 0;
}
