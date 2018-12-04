#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <ctype.h>
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
#define mod 1000000007

using namespace std;

i64 big_mod(i64 b, i64 p, i64 m)
{
    if(!p) return 1;
    i64 x = big_mod(b, p/2, m);
    x = ((x%m)*(x%m)) % m;
    if(p&1)
        x = ((b%m)*(x%m)) % m;

    return x;
}


main()
{
    //freopen("text_input.txt", "r", stdin);
    //freopen("text_output.txt", "w", stdout);

    i64 N, L, i;
    while(scanf("%lld%lld", &N, &L)==2, N, L) {
        i64 s=0, a;
        for(i=1; i<=L; i++) {
            a = big_mod(N, i, mod)%mod;
            s = (s%mod + a%mod)%mod;
        }

        printf("%lld\n", s);
    }
}
