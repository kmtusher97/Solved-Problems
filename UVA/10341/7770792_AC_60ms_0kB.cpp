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
#define MX 1000000
#define EPS 1e-9

double p, q, r, s, t, u, root;

double F(double x)
{
    return ( (p*exp(-x)) + (q*sin(x)) + (r*cos(x)) + (s*tan(x)) + (t*x*x) + u );
}

double biSection()
{
    double mid, low=0.0, high=1.0;

    for(int i=0; i<100; i++)
    {
        mid=(low+high)/2.0;
       // printf("%.4lf\n", F(mid));
        if(F(mid)*F(low) < 0) high=mid;
        else low=mid;
    }

    return mid;
}

main()
{
    //freopen("INPUT.txt", "r", stdin);
    //freopen("OUTPUT.txt", "w", stdout);

    while(scanf("%lf %lf %lf %lf %lf %lf", &p, &q, &r, &s, &t, &u) == 6)
    {
        if(F(0) == 0) printf("0.0000\n");
        else if(F(1.0) == 0) printf("1.0000\n");
        else if((F(0)*F(1.0)) >= EPS) printf("No solution\n");
        else {
            root=biSection();

            printf("%.4lf\n", root);
        }
    }
}
