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
        dd r, sA, sC;
        scanf("%lf", &r);
        sC=PI*r*r;
        sA=4*r*r;
        printf("Case %d: %.2lf\n", ++t, sA-sC);
    }
}
