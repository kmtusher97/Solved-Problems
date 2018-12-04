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

map<int, int> dp[25];
vector<int> v;
int w, n, i, arr[22];

int recursion(int pos, int sum)
{
    if(pos == n) return sum;
    if(dp[pos].find(sum) != dp[pos].end()) return dp[pos][sum];

    int nibo=0, nibona;
    ///nibona;
    nibona = recursion(pos+1, sum);
    ///nibo;
    if(sum+arr[pos] <= w) nibo = recursion(pos+1, sum+arr[pos]);
    dp[pos][sum]=max(nibo, nibona);

    return dp[pos][sum];
}

int recursionPrint(int pos, int sum)
{
    if(pos == n) return sum;
    //if(dp[pos].find(sum) != dp[pos].end()) return sum;

    int nibo=0, nibona;
    ///nibona;
    nibona = recursion(pos+1, sum);
    ///nibo;
    if(sum+arr[pos] <= w) nibo = recursion(pos+1, sum+arr[pos]);
    //dp[pos][sum]=max(nibo, nibona);

    if(dp[pos][sum] == nibo) {
        v.push_back(arr[pos]);
        recursionPrint(pos+1, sum+arr[pos]);
    }
    else recursionPrint(pos+1, sum);

    return dp[pos][sum];
}

main()
{
    //freopen("INPUT.txt", "r", stdin);
    //freopen("OUTPUT.txt", "w", stdout);

    while(scanf("%d%d", &w, &n) == 2) {
        for(i=0; i<n; i++) scanf("%d", &arr[i]);
        for(i=0; i<n; i++) { dp[i].clear(); }
        int sum = recursion(0, 0);
        v.clear();
        recursionPrint(0, 0);
        int sz=v.size();
        for(i=0; i<sz; i++) { printf("%d ", v[i]); }
        printf("sum:%d\n", sum);
    }
}
