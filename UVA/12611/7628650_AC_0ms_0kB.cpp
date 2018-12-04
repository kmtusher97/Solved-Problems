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

using namespace std;

main()
{
    //freopen("text_input.txt", "r", stdin);
    //freopen("text_output.txt", "w", stdout);
    int tc, t=0;
    scanf("%d", &tc);
    while(tc--) {
        dd L, W, R, xr, xl, yr, yl;
        scanf("%lf", &R);

        L=R/0.2;
        W=0.6*L;
        xr=L*0.55;
        xl=xr-L;
        yr=0.5*W;
        yl=-1.0*yr;

        printf("Case %d:\n", ++t);
        printf("%.0lf %.0lf\n%.0lf %.0lf\n%.0lf %.0lf\n%.0lf %.0lf\n", xl, yr, xr, yr, xr, yl, xl, yl);
    }
}
