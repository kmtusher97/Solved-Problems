#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define pbk pop_back
#define mk_pr make_pair

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<string> vss;
typedef queue<int> qi;

const int MX = 1123456;
int a[MX];

int main() {
  int cases, n, k;
  scanf("%d", &cases);
  while( cases-- ) {
    scanf("%d %d", &n, &k);
    for(int i=0; i<n; i++) {
      scanf("%d", a+i);
    }
    sort(a, a+n);
    int mn = INT_MAX;
    for(int i=0; i+k-1<=n-1; i++) {
      mn = min(mn, a[i+k-1]-a[i]);
    }
    printf("%d\n", mn);
  }
  return 0;
}
