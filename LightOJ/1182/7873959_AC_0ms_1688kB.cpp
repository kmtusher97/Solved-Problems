#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

main()
{
    int cases, caseno = 0, n, prty;
    scanf("%d", &cases);
    while( cases-- ) {
        scanf("%d", &n);
        prty = __builtin_popcount(n);
        if( prty&1 ) printf("Case %d: odd\n", ++caseno);
        else printf("Case %d: even\n", ++caseno);
    }
}
