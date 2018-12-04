/* BISMILLAHIR RAHMANIR RAHIM */
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MX_N 100005
const ll inf = 1e14;
int n, K;
ll w[MX_N], qsum[MX_N];

ll ff[2][MX_N];

ll cost( int i, int j ) {
  ll ret = qsum[j] - qsum[i - 1];
  ret -= ((w[j] - w[i - 1]) * (i - 1));
  return ret;
}

void calculation( int i, int l, int r, int L, int R ) { ///D&C optimization
  if( l > r ) return;

  int mid = l + (r - l) / 2;
  ff[i][mid] = inf;
  int id = -1;
  for(int j = L; j <= min(mid, R); j++)
    if( ff[i][mid] > ff[i ^ 1][j] + cost( j + 1, mid ) )
      ff[i][mid] = ff[i ^ 1][j] + cost( j + 1, mid ), id = j;

  calculation( i, l, mid - 1, L, ~id ? id : R );
  calculation( i, mid + 1, r, ~id ? id : L, R );
}

ll solution() {
  for(int i = 1; i <= n; i++)
    ff[1][i] = cost( 1, i );

  for(int i = 2; i <= K; i++)
    calculation( i % 2, 1, n, 1, n );

  return ff[K % 2][n];
}

int main() {
  scanf("%d %d", &n, &K);
  for(int i = 1; i <= n; i++) {
    scanf("%lld", w + i);
    qsum[i] = qsum[i - 1] + ((i - 1) * w[i]);
    w[i] += w[i - 1];
  }

  ll res = solution();
  printf("%lld\n", res);

  return 0;
}
