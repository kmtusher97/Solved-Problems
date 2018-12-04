#include <bits/stdc++.h>
using namespace std;

const int MX = 10000067;
double d[MX];

void precal() {
  d[1] = 0;
  for(int i=2; i<MX; i++) {
    d[i] = log10(i*1.0) + d[i-1];
  }
}

int main() {
  precal();
  int cases, n;
  scanf("%d", &cases);
  while( cases-- ) {
    scanf("%d", &n);
    n == 1 ? printf("1\n") : printf("%d\n", (int)ceil(d[n]));
  }
  return 0;
}
