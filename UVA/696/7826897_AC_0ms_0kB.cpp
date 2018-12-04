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
#define MX 500000
#define EPS 1e-9

//int dx4[] = { 0, 0, 1, -1 };
//int dy4[] = { 1, -1, 0, 0 };
//int dx8[] = { 0, 0, 1, -1, -1, 1, 1, -1 };
//int dy8[] = { 1, -1, 0, 0, -1, 1, -1, 1 };

main()
{
    //freopen("INPUT.txt", "r", stdin);
    //freopen("OUTPUT.txt", "w", stdout);

    int m, n, a, t;
    while( scanf("%d %d", &m, &n) == 2 && m && n ) {
        if( m == 1 || n == 1 ) t = m*n;
        else if( m == 2 ) {
            if( n&1 ) a = (n/2)+1;
            else {
                a = n/2;
                if( a&1 ) a++;
            }
            t = a * 2;
        }
        else if( n == 2 ) {
            if( m&1 ) a = (m/2)+1;
            else {
                a = m/2;
                if( a&1 ) a++;
            }
            t = a * 2;
        }
        else {
            if( (m*n)&1 ) t = ( (m*n)/2 ) + 1;
            else t = (m*n)/2;
        }
        printf("%d knights may be placed on a %d row %d column board.\n", t, m, n);
    }
}
