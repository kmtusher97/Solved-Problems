/**  ~*BISMILLAHIR RAHMANIR RAHIM*~  **/

#include <bits/stdc++.h>
using namespace std;

const int MX = 1004;
int ff[MX][MX];
string a, b;

int main()
{
  ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int cases;
  cin>>cases, cin.ignore();
  while( cases-- )
  {
    getline(cin, a), b = a;
    reverse(b.begin(), b.end());
    memset(ff, 0, sizeof ff);
    for(int i=1; i<=a.size(); i++)
    {
      for(int j=1; j<=b.size(); j++)
      {
        if( a[i-1]==b[j-1] ) ff[i][j] = 1 + ff[i-1][j-1];
        else ff[i][j] = max(ff[i-1][j], ff[i][j-1]);
      }
    }
    cout<<ff[a.size()][a.size()]<<endl;
  }
  return 0;
}
