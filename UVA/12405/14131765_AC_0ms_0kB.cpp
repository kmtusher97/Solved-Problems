/*  ~*BISMILLAHIR RAHMANIR RAHIM*~  */

#include <bits/stdc++.h>
using namespace std;

#define MX_N 102
int n;
char land[MX_N];

int main() {
  int cases, caseno = 0;
  scanf("%d", &cases);
  while( cases-- ) {
    scanf("%d %s", &n, land);
    int res = 0;
    for(int i=0; i<n; ) {
      if( land[i]=='.' ) res++, i += 3;
      else i++;
    }
    printf("Case %d: %d\n", ++caseno, res);
  }
  return 0;
}
