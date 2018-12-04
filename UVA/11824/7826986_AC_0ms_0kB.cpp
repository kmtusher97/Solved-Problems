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
#include <list>

using namespace std;

#define LL long long
#define uLL unsigned long long
#define DD double
#define LDD long double
#define PI acos(-1)
#define modulo 40000
#define MX 5000000
#define EPS 1e-9

//int dx4[] = { 0, 0, 1, -1 };
//int dy4[] = { 1, -1, 0, 0 };
//int dx8[] = { 0, 0, 1, -1, -1, 1, 1, -1 };
//int dy8[] = { 1, -1, 0, 0, -1, 1, -1, 1 };

int power(int n, int x)
{
    if( !x ) return 1;
    int b = power(n, x/2);
    b *= b;
    if( x&1 ) b *= n;
    return b;
}

main()
{
    //freopen("INPUT.txt", "r", stdin);
    //freopen("OUTPUT.txt", "w", stdout);

    int cases, caseno=0, n, i, a, arr[50], sm, p;
    scanf("%d", &cases);
    while( cases-- ) {
        n = 0;
        while( true ) {
            scanf("%d", &a);
            if( !a ) break;
            arr[n++] = a;
        }
        sort(arr, arr+n);
        bool flg = true;
        for(i=n-1, p=1, sm=0; i>=0; i--, p++) {
            sm += ( 2 * power(arr[i], p) );
            if( sm > MX ) {
                printf("Too expensive\n");
                flg = false;
                break;
            }
        }
        if( flg ) printf("%d\n", sm);
    }
}
