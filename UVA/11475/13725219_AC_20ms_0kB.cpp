/**  ~*BISMILLAHIR RAHMANIR RAHIM*~  **/

#include <bits/stdc++.h>

using namespace std;

typedef long long intl;

const int MX = 112345;
string s1, s2;

struct KMP
{
  int f[MX];

  void process( string s )
  {
    f[0] = -1;
    for(int i=0, j=-1; s[i]; )
    {
      while( j>=0 && s[j]!=s[i] ) j = f[j];
      f[++i] = ++j;
    }
  }
  int customSearch( string T, string P )
  {
    int i, j, n = T.size(), m = P.size();
    for(i=0, j=0; T[i]; )
    {
      while( j>=0 && T[i]!=P[j] ) j = f[j];
      i++, j++;
      if( j==m ) return m;
    }
    return j;
  }
} bb;

int main()
{
  ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  while( cin>>s1 )
  {
    s2 = s1;
    reverse(s2.begin(), s2.end());
    bb.process( s2 );
    int indx = bb.customSearch( s1, s2 );
    cout<<s1;
    for(int i=indx; s2[i]; i++) cout<<s2[i];
    cout<<endl;
  }
  return 0;
}
