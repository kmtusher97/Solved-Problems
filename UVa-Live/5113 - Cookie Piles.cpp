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

int main() {
  int cases, n, a, d;
  scanf("%d", &cases);
  while( cases-- ) {
    scanf("%d %d %d", &n, &a, &d);
    int ans = n*a + d*(((n-1)*n)/2);
    printf("%d\n", ans);
  }
  return 0;
}
