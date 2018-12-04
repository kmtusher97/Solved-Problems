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
        int x, y, x1, y1, x2, y2, x3, y3, area;
        scanf("%d%d%d%d%d%d", &x, &y, &x1, &y1, &x2, &y2);
        x3=x2-x1+x;
        y3=y2-y1+y;

        area=abs((x*y1 + x1*y2 + x2*y) - (x*y2 + x2*y1 + x1*y));

        printf("Case %d: %d %d %d\n", ++t, x3, y3, area);
    }
}
