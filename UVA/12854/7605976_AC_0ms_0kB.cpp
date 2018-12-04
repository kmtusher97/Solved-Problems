// UVA 12854 - Automated Checking Machine
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

using namespace std;

main()
{
    //freopen("file_input.txt", "r", stdin);
    //freopen("file_output.txt", "w", stdout);

    int a[5], b[5], i;
    while(scanf("%d", &a[0])==1) {
        for(i=1; i<5; i++)
            scanf("%d", &a[i]);

        for(i=0; i<5; i++)
            scanf("%d", &b[i]);
        bool chk=true;

        for(i=0; i<5; i++)
            if((!a[i] && !b[i]) || (a[i] && b[i])) {
                chk=false;
                break;
            }
        if(chk) printf("Y\n");
        else printf("N\n");
    }
}
