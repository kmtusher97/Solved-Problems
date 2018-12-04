/**  ~*BISMILLAHIR RAHMANIR RAHIM*~  **/

#include <bits/stdc++.h>

using namespace std;

typedef long long intl;

const int MX = 112345;
int phi[MX];
bool vis[MX];

void seivephi()
{
  for(int i=1; i<MX; i++) phi[i] = i;
  phi[1] = vis[1] = 1;

  for(int i=2; i<MX; i++)
  {
    if( vis[i] ) continue;
    for(int j=i; j<MX; j+=i)
    {
      vis[j] = 1;
      phi[j] = phi[j]/i*(i-1);
    }
  }
}

int main()
{
  ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  seivephi();
  phi[1] = 0;
  int cases;
  cin>>cases;
  while( cases-- )
  {
    int n;
    cin>>n;
    cout<<phi[n]<<endl;
  }
  return 0;
}
