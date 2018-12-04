/**    ~* BISMILLAHIR RAHMANIR RAHIM *~    **/

#include <bits/stdc++.h>

using namespace std;

typedef long long intl;

const int MX = 1123456;
int n, a[MX];
intl bit[MX];

void update( int id, int v )
{
  while( id<=n )
  {
    bit[id] += v;
    id += (id&-id);
  }
}

intl query( int id )
{
  intl sm = 0;
  while( id>0 )
  {
    sm += bit[id];
    id -= (id&-id);
  }
  return sm;
}

int main()
{
  ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int caseno = 0;
  while( cin>>n && n>0 )
  {
    for(int i=1; i<=n; i++)
    {
      cin>>a[i];
      update( i, a[i] );
    }
    string s;
    if( caseno ) cout<<endl;
    cout<<"Case "<<++caseno<<":"<<endl;
    while( cin>>s && s!="END" )
    {
      int x, y;
      if( s=="M" )
      {
        cin>>x>>y;
        intl ans = query( y ) - query( x-1 );
        cout<<ans<<endl;
      }
      else
      {
        cin>>x>>y;
        update( x, -a[x] );
        update( x, y );
        a[x] = y;
      }
    }
    memset(bit, 0, sizeof bit);
  }

  return 0;
}
