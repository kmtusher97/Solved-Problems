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

using namespace std;

int big_mod(int b, int p, int m)
{
    if(!p) return 1;
    int x = big_mod(b, p/2, m);
    x = (x%m * x%m) % m;
    if(p&1)
        x = (b%m * x%m) % m;

    return x;
}


main()
{
    //freopen("text_input.txt", "r", stdin);
    //freopen("text_output.txt", "w", stdout);

    int b, p, m;
    while(scanf("%d%d%d", &b, &p, &m)==3) {
        printf("%d\n", big_mod(b, p, m));
    }
}
