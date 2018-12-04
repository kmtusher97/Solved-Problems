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
#define PI acso(-1)
#define modulo 1000003
#define MX 500000
#define EPS 1e-9

int a, b, c, a1, b1, c1;
double x, y;

main()
{
    //freopen("INPUT.txt", "r", stdin);
    //freopen("OUTPUT.txt", "w", stdout);

    while(scanf("%d%d%d", &a, &b, &c)==3)
    {
        scanf("%d%d%d", &a1, &b1, &c1);
        if(!a && !b && !c && !a1 && !b1 && !c1) break;

        if( !(a*b1 - a1*b) ) printf("No fixed point exists.\n");
        else
        {
            x = (double)(c*b1 - c1*b)/(double)(a*b1 - a1*b);
            y = (double)(a*c1 - a1*c)/(double)(a*b1 - a1*b);

            printf("The fixed point is at %.2lf %.2lf.\n", x, y);
        }
    }
}
