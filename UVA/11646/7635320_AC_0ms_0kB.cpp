// practice
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <climits>

#define ll long long
#define ull unsigned long long
#define dd double
#define ldd long double
#define PI acos(-1)

using namespace std;

main()
{
    //freopen("text_input.txt", "r", stdin);
    //freopen("text_output.txt", "w", stdout);

    int tc=0;
    dd m, n;
    while(scanf("%lf : %lf", &m, &n)==2) {
        dd r, s, angle, o, L, W;

        r=sqrt((m*m)+(n*n))/2.0;
        angle=asin((n/2.0)/r)*2;
        s=r*angle*2.0;
        //printf("%lf", s);
        o=((2.0*m)*400.0)/((2.0*m)+s);
        L=o/2.0;
        W=(L/m)*n;

        printf("Case %d: %.10lf %.10lf\n", ++tc, L, W);
    }
}
