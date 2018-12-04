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

int arr[30], cnt=0;
bool vis[30];

void permutation(int i, int n, int k)
{
    if(cnt==k) return;
    if(i==n) {
        cnt++;
        for(int l=0; l<n; l++)
            printf("%c", arr[l]+64);
        printf("\n");
        return;
    }

    for(int j=1; j<=n; j++) {
        if(!vis[j]) {
            vis[j]=1;
            arr[i]=j;
            permutation(i+1, n, k);
            vis[j]=0;
        }
    }
}

main()
{
    //freopen("INPUT.txt", "r", stdin);
    //freopen("OUTPUT.txt", "w", stdout);

    int tc, t=0, n, k, i;
    scanf("%d", &tc);
    while(tc--)
    {
        scanf("%d%d", &n, &k);
        memset(vis, 0, sizeof(vis));
        cnt=0;
        printf("Case %d:\n", ++t);
        permutation(0, n, k);
    }
}
