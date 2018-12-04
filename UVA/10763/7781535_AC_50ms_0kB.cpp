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
#define MX 500000
#define EPS 1e-9

int arr[MX+5];

main()
{
    //freopen("INPUT.txt", "r", stdin);
    //freopen("OUTPUT.txt", "w", stdout);

    int n, i, a, b, p;
    while(scanf("%d", &n), n)
    {
        bool chk=true;

        memset(arr, 0, sizeof(arr));

        for(i=0; i<n; i++) {
            scanf("%d%d", &a, &b);
            arr[a]++, arr[b]++;
        }

        for(i=0; i<=MX; i++)
            if(arr[i] && arr[i]&1) { chk=false; break; }

        if(!chk) printf("NO\n");
        else printf("YES\n");
    }
}
