/*  ~*BISMILLAHIR RAHMANIR RAHIM  */
#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define pb push_back

typedef long long intl;
typedef vector<int> vi;
typedef pair<int, int> pii;

const int MX_N = 2050;
intl s, n, w[MX_N], v[MX_N], ff[MX_N][MX_N];

int main() {
  ios_base :: sync_with_stdio(false); cin.tie(NULL), cout.tie(NULL);
  cin >> s >> n;
  for(int i = 1; i <= n; i++)
    cin >> w[i] >> v[i];
  memset(ff, 0, sizeof ff);

  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= s; j++) {
      if( w[i] > j ) ff[i][j] = ff[i - 1][j];
      else ff[i][j] = max( ff[i - 1][j], v[i] + ff[i - 1][j - w[i]] );
    }
  }
  cout << ff[n][s] << endl;
  return 0;
}

