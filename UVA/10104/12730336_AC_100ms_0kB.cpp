/**    ~* BISMILLAHIR RAHMANIR RAHIM *~    **/

#include <bits/stdc++.h>

using namespace std;

typedef long long intl;

intl a, b, x, y, c;

void extended_gcd( int A, int B )
{
  if( B==0 )
  {
    c = A, x = 1, y = 0;
    return;
  }

  extended_gcd( B, A%B );
  intl tmp = x;
  x = y;
  y = tmp - (A/B)*y;
}

int main()
{
  ios_base :: sync_with_stdio( false ); cin.tie(NULL); cout.tie(NULL);
  while( cin>>a>>b )
  {
    extended_gcd( a, b );
    cout<<x<<" "<<y<<" "<<c<<endl;
  }
  return 0;
}
