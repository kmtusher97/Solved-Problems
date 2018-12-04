/** ~*BISMILLAHIR RAHMAIR RAHIM*~ **/

#include <bits/stdc++.h>

using namespace std;

typedef long long intl;

const int MX = 1123456;

string rvrs( string s )
{
  string s1 = "";
  for(int i=s.size()-1; i>=0; i--)
  {
    s1 += s[i];
  }
  return s1;
}

string add( string a, string b )
{
  int carry = 0, i = 0, j = 0, n = a.size(), m = b.size();
  string sm = "";
  while( true )
  {
    if( i>=n && j>=m ) break;
    else if( i<n && j<m )
    {
      int s = (a[i]-'0')+(b[j]-'0')+carry;
      sm += (s%10+'0');
      carry = s/10;
      i++, j++;
    }
    else if( i<n )
    {
      int s = (a[i]-'0')+carry;
      sm += (s%10+'0');
      carry = s/10;
      i++;
    }
    else if( j<m )
    {
      int s = (b[j]-'0')+carry;
      sm += (s%10+'0');
      carry = s/10;
      j++;
    }
  }
  if( carry )
  {
    sm += (carry+'0');
  }
  return sm;
}

int main()
{
  ios_base :: sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
  int cases;
  cin>>cases;
  while( cases-- )
  {
    string a, b;
    cin>>a>>b;
    string sm = add( a ,b );
    bool f = true;
    for(int i=0; i<sm.size(); i++)
    {
      if( sm[i]!='0' ) f = false;
      if( !f ) cout<<sm[i];
    }
    cout<<endl;
  }
  return 0;
}
