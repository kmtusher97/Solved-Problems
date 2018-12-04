/*  ~*BISMILLAHIR RAHMANIR RAHIM*~  */

#include <bits/stdc++.h>
using namespace std;

#define MX_N 100002
int n, a[MX_N], L[MX_N], R[MX_N], tmp[MX_N];

void LIS() {
  tmp[0] = INT_MIN;
  for(int i=1; i<=n; i++) tmp[i] = INT_MAX;

  int lnth = 0;
  for(int i=0; i<n; i++) {
    int lo = 0, hi = lnth;
    while( lo<=hi ) {
      int mid = lo+(hi-lo)/2;
      if( tmp[mid]<a[i] ) lo = mid+1;
      else hi = mid-1;
    }
    tmp[lo] = a[i], L[i] = lo;
    lnth = max(lo, lnth);
  }
}

void LDS() {
  tmp[0] = INT_MIN;
  for(int i=1; i<=n; i++) tmp[i] = INT_MAX;

  int lnth = 0;
  for(int i=n-1; i>=0; i--) {
    int lo = 0, hi = lnth;
    while( lo<=hi ) {
      int mid = lo+(hi-lo)/2;
      if( tmp[mid]<a[i] ) lo = mid+1;
      else hi = mid-1;
    }
    tmp[lo] = a[i], R[i] = lo;
    lnth = max(lo, lnth);
  }
}

int main() {
  int cases, caseno = 0;
  scanf("%d", &cases);
  while( cases-- ) {
    scanf("%d", &n);
    for(int i=0; i<n; i++) scanf("%d", a+i);
    LIS();
    LDS();
    int res = 1;
    for(int i=0; i<n; i++) {
      res = max(res, min(L[i], R[i]));
    }
    printf("Case %d: %d\n", ++caseno, res*2-1);
  }
  return 0;
}
