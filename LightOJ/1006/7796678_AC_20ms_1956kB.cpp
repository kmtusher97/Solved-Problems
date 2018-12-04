#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <iomanip>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <stack>
#include <queue>

using namespace std;

#define LL long long
#define uLL unsigned long long
#define DD double
#define LDD long double
#define PI acos(-1)
#define modulo 10000007
#define MX 10000
#define EPS 1e-9

LL Hxb[MX+7];
int a, b, c, d, e, f;

LL fn( int n )
{
    if( n == 0 ) return a;
    if( n == 1 ) return b;
    if( n == 2 ) return c;
    if( n == 3 ) return d;
    if( n == 4 ) return e;
    if( n == 5 ) return f;

    if( Hxb[n] != -1 ) return Hxb[n];

    Hxb[n] = ( fn(n-1) + fn(n-2) + fn(n-3) + fn(n-4) + fn(n-5) + fn(n-6) ) % modulo;

    return Hxb[n];
}

main()
{
    //freopen("INPUT.txt", "r", stdin);
    //freopen("OUTPUT.txt", "w", stdout);

    int n, caseno = 0, cases;
    scanf("%d", &cases);
    while( cases-- ) {
        scanf("%d %d %d %d %d %d %d", &a, &b, &c, &d, &e, &f, &n);
        memset( Hxb, -1, sizeof(Hxb) );  ///initializing with -1
        printf("Case %d: %d\n", ++caseno, fn(n) % 10000007);
    }
}
