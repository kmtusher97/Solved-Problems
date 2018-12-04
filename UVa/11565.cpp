#include <bits/stdc++.h>
using namespace std;
const int MX = 10000;

int main() {
  int cases, A, B, C;
  scanf("%d", &cases);
  while( cases-- ) {
    scanf("%d %d %d", &A, &B, &C);
    bool flg = false;
    for(int i=-100; i<=100; i++) {
      for(int j=-100; j<=100; j++) {
        for(int k=-100; k<=100; k++) {
          if( i != j && i != k && j != k && i+j+k == A && i*j*k == B && i*i+j*j+k*k == C ) {
            printf("%d %d %d\n", i, j, k);
            flg = true; break;
          }
        }
        if( flg ) break;
      }
      if( flg ) break;
    }
    if( !flg ) {
      printf("No solution.\n");
    }
  }
  return 0;
}
