#include <iostream>
#include <iomanip>
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

i64 big_mod(i64 b, i64 p, i64 m)
{
    if(!p) return 1;
    i64 x = big_mod(b, p/2, m);

    x = (x%m * x%m) % m;

    if(p&1)
        x = (b%m * x%m) % m;

    return x;
}

main()
{
    //freopen("text_input.txt", "r", stdin);
    //freopen("text_output.txt", "w", stdout);

    int tc;
    while(scanf("%d", &tc)==1, tc) {
        while(tc--) {
            i64 base, power, mod;
            scanf("%lld %lld %lld", &base, &power, &mod);
            printf("%lld\n", big_mod(base, power, mod));
        }
    }
}
