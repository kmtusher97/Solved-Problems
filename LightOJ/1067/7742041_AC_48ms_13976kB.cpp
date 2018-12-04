#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <iomanip>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <stack>
#include <queue>

using namespace std;

#define LL long long
#define uLL unsigned long long
#define DD double
#define LDD long double
#define PI acso(-1)
#define modulo 1000003
#define MX 1000000
#define new_line printf("\n")


LL big_mod(LL b, LL p, LL m)
{
    if(!p) return 1;
    LL x = big_mod(b, p/2, m);
    x = (x%m * x%m) % m;
    if(p&1)
        x = (b%m * x%m) % m;

    return x;
}

vector<LL> factorials;

void all_facts()
{
    factorials.push_back(1);

    for(LL i=1; i<=modulo; i++)
    {
        LL a = ((i % modulo) * (factorials.at(i-1) % modulo)) % modulo;
        factorials.push_back(a);
    }
}


main()
{
    //freopen("text_input.txt", "w", stdin);
    //freopen("text_output.txt", "w", stdout);

    all_facts();

    int tc, t=0;
    scanf("%d", &tc);
    while(tc--) {
        long long n, r, ans, x, y, z;
        scanf("%lld%lld", &n, &r);

        x = factorials.at(n) % modulo;
        y = (factorials.at(n-r) % modulo * factorials.at(r) % modulo) % modulo;
        z = big_mod(y, modulo-2, modulo);
        ans = (x*z) % modulo;

        printf("Case %d: %lld\n", ++t, ans);
    }

}
