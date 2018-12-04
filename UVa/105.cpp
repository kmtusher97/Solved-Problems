/*
    UVa problem 105 - The Skyline Problem
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <vector>

#define ll long long
#define dd double
#define MX 10000
#define MX1 5000
#define MX2 16000

using namespace std;

int v[MX2], L, H, R;

main()
{
    //freopen("text_input.txt", "r", stdin);
    //freopen("text_output.txt", "w", stdout);

    int i, lmn=MX, rmx=0;

    while(scanf("%d%d%d", &L, &H, &R)==3) {
        lmn=min(lmn, L);
        rmx=max(rmx, R);

        for(i=L; i<R; i++) {
            v[i]=max(v[i], H);
        }
    }

    v[lmn-1]=MX+5;
    for(i=lmn; i<=rmx; i++)
        if(v[i]!=v[i-1]) {
            printf("%d %d", i, v[i]);
            if(i==rmx) printf("\n");
            else printf(" ");
        }
}
