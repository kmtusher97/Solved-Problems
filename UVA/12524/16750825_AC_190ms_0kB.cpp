/* BISMILLAHIR RAHMANIR RAHIM */
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
typedef long long ll;
typedef pair<ll, ll> pii;
#define MX_N 1005
const ll inf = 1e15;
int n, k;
ll w[MX_N], x[MX_N], qsum[MX_N], ff[2][MX_N];

ll Cost( int i, int j ) {
  ll ret = qsum[i] - qsum[j + 1];
  ll bad = (w[i] - w[j + 1]) * (x[n] - x[j]);
  return (ret - bad);
}

void compute( int i, int l, int r, int L, int R ) {
  if( l > r ) return;

  int mid = l + (r - l) / 2;
  ff[i][mid] = inf;
  int id = -1;
  for(int j = L; j <= min(mid, R); j++)
    if( ff[i][mid] > ff[i ^ 1][j] + Cost( j + 1, mid ) )
      ff[i][mid] = ff[i ^ 1][j] + Cost( j + 1, mid ), id = j;

  compute( i, l, mid - 1, L, ~id ? id : R );
  compute( i, mid + 1, r, ~id ? id : L, R );
}

ll solve() {
  for(int i = 1; i <= n; i++)
    ff[1][i] = Cost( 1, i );

  for(int i = 2; i <= k; i++)
    compute( i % 2, 1, n, 1, n );

  return ff[k % 2][n];
}

int main() {
  while( ~scanf("%d %d", &n, &k) ) {
    for(int i = 1; i <= n; i++)
      scanf("%lld %lld", x + i, w + i);

    qsum[n + 1] = w[n + 1] = 0LL;
    for(int i = n; i >= 1; i--) {
      qsum[i] = qsum[i + 1] + (w[i] * (x[n] - x[i]));
      w[i] += w[i + 1];
    }

    ll res = solve();
    printf("%lld\n", res);
  }

  return 0;
}
