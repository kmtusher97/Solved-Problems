/**  ~*BISMILLAHIR RAHMANIR RAHIM*~  **/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second

typedef long long intl;
typedef pair<int, int> pii;

const intl MX = 1123456;
int fct[MX];
intl ff[MX][12];

int prim_fct( int x )
{
  int cnt = 0, c = 0;
  if( x%2==0 ) {
    cnt++;
    while( x%2==0 )
    {
      x /= 2;
    }
    if( c>1 ) return -1;
  }

  for(int i=3; i<=sqrt(x); i+=2)
  {
    if( x%i==0 )
    {
      cnt++;
      while( x%i==0 )
      {
        x /= i;
      }
    }
  }

  if( x>1 ) cnt++;

  return cnt;
}

void precal()
{
  for(int i=2; i<=1e6+100; i++)
  {
    fct[i] = prim_fct( i );
  }
  for(int i=1; i<=(1e6)+100; i++)
  {
    for(int j=0; j<=11; j++)
    {
      ff[i][j] = ff[i-1][j];
    }
    if( fct[i]!=-1 )
    {
      ff[i][fct[i]]++;
    }
  }
}

int main()
{
  ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  precal();
  int cases;
  cin>>cases;
  while( cases-- )
  {
    int l, r, n;
    cin>>l>>r>>n;
    intl ans = ff[r][n]-ff[l-1][n];
    cout<<ans<<endl;
  }

  return 0;
}
