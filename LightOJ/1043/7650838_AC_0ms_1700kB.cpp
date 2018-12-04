#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>

#define ll long long
#define ull unsigned long long
#define dd double
#define ldd long double
#define PI acos(-1)

using namespace std;

main()
{
    //freopen("file_input.txt", "r", stdin);
    //freopen("file_output.txt", "w", stdout);

    int tc, t=0;
    scanf("%d", &tc);
    while(tc--) {
        dd a, b, c, r, r1, AREA, area, AD, s;
        scanf("%lf%lf%lf%lf", &a, &b, &c, &r);
        s=(a+b+c)/2.0;
        AREA=sqrt(s*(s-a)*(s-b)*(s-c));
        area=(r*AREA)/(r+1.0);
        r1=sqrt(area/AREA);
        AD=a*r1;

        printf("Case %d: %lf\n", ++t, AD);
    }
}
