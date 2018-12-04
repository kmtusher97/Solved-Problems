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
#define PI acos(-1)
#define modulo 1000003
#define MX 500000
#define EPS 1e-9

int prim[12] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37 }, arr[20];
bool mark[20];

int binarySearch(int l, int r, int x)
{
    if(l > r) return 0;
    int mid=(l+r)/2;
    if(prim[mid] == x) return 1;
    if(prim[mid] > x)
        return binarySearch(l, mid-1, x);
    else
        return binarySearch(mid+1, r, x);
}

void recursion(int p, int n)
{
    if(p==n) {
        if( binarySearch(0, 11, arr[0]+arr[n-1]) ) {
            printf("1");
            for(int j=1; j<n; j++)
                printf(" %d", arr[j]);
            printf("\n");
        }
        return;
    }

    for(int i=2; i<=n; i++) {
        if( !mark[i] && binarySearch(0, 11, i+arr[p-1]) ) {
            arr[p]=i;
            mark[i]=1;
            recursion(p+1, n);
            mark[i]=0;
        }
    }
}

main()
{
    //freopen("INPUT.txt", "r", stdin);
    //freopen("OUTPUT.txt", "w", stdout);
    int n, t=0;
    while(scanf("%d", &n)==1) {
        if(t) printf("\n");
        memset(mark, 0, sizeof(mark));
        printf("Case %d:\n", ++t);
        arr[0]=1;
        recursion(1, n);
        //printf("\n");
    }
}
