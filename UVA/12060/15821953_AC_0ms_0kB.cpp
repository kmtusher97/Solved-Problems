/*  BISMILLAHIR RAHMANIR RAHIM  */
#include <bits/stdc++.h>
using namespace std;
typedef long long intl;

string mkstr( intl x ) {
  string ret = "";
  if( x == 0 ) return "0";
  int xx = abs(x);
  while( xx > 0 ) {
    ret += (xx % 10 + '0');
    xx /= 10;
  }
  reverse(ret.begin(), ret.end());
  return ret;
}

void prntFn1( intl d, intl n ) {
  string hor = mkstr( n );
  string lob = mkstr( d );
  string by = "";
  int lnh = hor.length(), lnl = lob.length();

  for(int i = 0; i < lnh - lnl; lob = " " + lob, i++);
  for(int i = 0; i < lnh; by += "-", i++);
  if( d * n < 0 ) {
    lob = "  " + lob;
    by = "- " + by;
    hor = "  " + hor;
  }
  cout << lob << "\n" << by << "\n" << hor << "\n";
}

void prntFn2( intl d, intl n ) {

  string hor = mkstr( n );
  string lob = mkstr( d % n );
  string by = mkstr( d / n );

  int lnh = hor.length(), lnl = lob.length(), lnby = max(lnh, lnh) + by.length();

  for(int i = 0; i < lnby - lnl; lob = " " + lob, i++);
  for(int i = 0; i < by.length(); hor = " " + hor, i++);
  for(int i = 0; i < lnh; by += "-", i++);
  if( d * n < 0 ) {
    lob = "  " + lob;
    by = "- " + by;
    hor = "  " + hor;
  }
  cout << lob << "\n" << by << "\n" << hor << "\n";
}

int main() {
  int n, caseno = 0;
  while( scanf("%d", &n) == 1 && n ) {
    intl sum = 0;
    for(int i = 1, a; i <= n; i++)
      scanf("%d", &a), sum += a;

    intl gcd = __gcd(abs(n * 1LL), abs(sum)), dnm, nmt;
    dnm = sum / gcd;
    nmt = n / gcd;
    printf("Case %d:\n", ++caseno);
    if( dnm == 0 ) {
      printf("0\n");
      continue;
    }
    if( nmt == 1 ) {
      if( dnm * nmt < 0 ) printf("- ");
      printf("%lld\n", abs(dnm));
      continue;
    }

    if( abs(dnm) < abs(nmt) )
      prntFn1( dnm, nmt );
    else
      prntFn2( dnm, nmt );
  }
  return 0;
}
