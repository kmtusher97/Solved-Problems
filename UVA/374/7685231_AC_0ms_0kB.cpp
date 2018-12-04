#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <climits>
#include <algorithm>
#include <vector>
#include <map>


#define i64 long long
#define i64u unsigned long long
#define d64 double
#define ld64 long double
#define pi acos(-1)

using namespace std;

i64 big_mod(i64 b, i64 p, i64 m)
{
    if(p == 0) return 1;

    if(p%2 == 0) {
        i64 ans = big_mod(b, p/2, m);
        return (ans%m * ans%m)%m;
    }
    else {
        return (b%m * big_mod(b, p-1, m))%m;
    }
}

main()
{
    i64 b, p, m;

    while(scanf("%lld%lld%lld", &b, &p, &m)==3) {
        printf("%lld\n", big_mod(b, p, m));
    }
}
