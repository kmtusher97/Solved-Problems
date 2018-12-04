#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <climits>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

#define PI acos(-1)
#define i64 long long
#define ui64 unsigned long long
#define d64 double
#define ld64 long double
#define moduls 1000000007

i64 big_mod(i64 base, i64 power, i64 mod)
{
    if(!power) return 1;
    i64 x = big_mod(base, power/2, mod);
    x = ((x%mod)*(x%mod))%mod;
    if(power&1)
        x = ((base%mod)*(x%mod))%mod;

    return x;
}

main()
{
    int tc, t=0;
    scanf("%d", &tc);
    while(tc--) {
        i64 n, ans;
        scanf("%lld", &n);
        ans = big_mod(2, n-1, moduls);
        ans = ((ans%moduls)*(n%moduls))%moduls;
        printf("Case #%d: %lld\n", ++t, ans);
    }
}
