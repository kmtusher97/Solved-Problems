#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <climits>
#include <vector>
#include <map>

#define PI acos(-1)
#define i64 long long
#define ui64 unsigned long long
#define d64 double
#define dd64 long double
#define MX 32000

using namespace std;

main()
{
    //freopen("text_input.txt", "r", stdin);
    //freopen("text_output.txt", "w", stdout);

    int tc, t=0;
    scanf("%d", &tc);
    getchar();
    d64 R, r, a, n;

    while(tc--) {
        scanf("%lf%lf", &R, &n);
        a = 1.0/sin(PI/(n*1.0));
        r = R/(1.0 + a);
        printf("Case %d: %.10lf\n", ++t, r);
    }
}
