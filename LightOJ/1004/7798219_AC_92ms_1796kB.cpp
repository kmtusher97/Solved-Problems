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
#define modulo 10000007
#define MX 10000
#define EPS 1e-9

vector<int> arr[210];
int dp[220][120], n, lim;

int go(int p, int q)
{
    if(p == lim) return 0;
    if(q < 0 || q >= arr[p].size()) return -1000000;
    if(dp[p][q] != -1) return dp[p][q];

    int sm1=0, sm2=0;
    if(p < n-1) {
        sm1 = arr[p][q] + go(p+1, q);
        sm2 = arr[p][q] + go(p+1, q+1);
    }
    else {
        if(q == 0) {
            sm1 = arr[p][q] + go(p+1, q);
            //if(arr[p+1].size() > 1) sm2 = arr[p][q] + go(p+1, q+1);
        }
        else if(q == arr[p].size()-1) sm1 = arr[p][q] + go(p+1, q-1);
        else {
            if(q-1 >= 0) sm1 = arr[p][q] + go(p+1, q-1);
            sm2 = arr[p][q] + go(p+1, q);
        }
    }
    int mx = max(sm1, sm2);
    dp[p][q] = mx;

    return dp[p][q];
}

main()
{
    //freopen("INPUT.txt", "r", stdin);
    //freopen("OUTPUT.txt", "w", stdout);

    int caseno = 0, cases, i, j, k, l, a;
    LL sm;
    scanf("%d", &cases);
    while( cases-- ) {
        scanf("%d", &n);
        for(i=0; i<=2*n; i++) arr[i].clear();  ///clearing the rows
        for(i=0; i<n; i++) {  /// input the diamond
        for(j=0; j<i+1; j++) {
            scanf("%d", &a), arr[i].push_back(a);
        }
        }
        for(k=n-1; k>=0; k--, i++) {
        for(j=0; j<k; j++) {
            scanf("%d", &a), arr[i].push_back(a);
        }
        }
        memset(dp, -1, sizeof dp);
        lim=2*n-1;
        printf("Case %d: %d\n", ++caseno, go(0, 0));
    }
}
