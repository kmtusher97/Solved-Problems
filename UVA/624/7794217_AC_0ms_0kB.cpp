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

map<int, int> mymap[25];
vector<int> ans;
int w, n, arr[22], i, x;

int dp(int p, int sum)
{
    if(p == n) return sum;   /// base case
    if(mymap[p].find(sum) != mymap[p].end())  return mymap[p][sum];

    int nibo=0, nibona=0;
    ///nibona
    nibona = dp(p+1, sum);
    ///nibo
    if(sum+arr[p] <= w) nibo = dp(p+1, sum+arr[p]);
    mymap[p][sum]=max(nibo, nibona);        /*store the maximum sum <= weight */

    return mymap[p][sum];
}

int pA(int p, int sum)
{
    if(p == n) return sum;   /// base case
    //if(mymap[p].find(sum) != mymap[p].end())  return mymap[p][sum];

    int nibo=0, nibona=0;
    ///nibona
    nibona = dp(p+1, sum);
    ///nibo
    if(sum+arr[p] <= w) nibo = dp(p+1, sum+arr[p]);
    //mymap[p][sum]=max(nibo, nibona);        /*store the maximum sum <= weight */

    if(mymap[p][sum] == nibo) {
        ans.push_back(arr[p]);
        pA(p+1, sum+arr[p]);
    }
    else pA(p+1, sum);

    return mymap[p][sum];
}

main()
{
    //freopen("INPUT.txt", "r", stdin);
    //freopen("OUTPUT.txt", "w", stdout);

    while(scanf("%d%d", &w, &n) == 2) {
        //input the array
        for(i=0; i<n; i++) scanf("%d", &arr[i]);
        //clear the map;
        for(i=0; i<22; i++) mymap[i].clear();
        ans.clear();
        int sum=dp(0, 0);  //initial position and sum both are 0
        pA(0, 0);
        int sz=ans.size();
        for(i=0; i<sz; i++) printf("%d ", ans[i]);
        printf("sum:%d\n", sum);
    }
}
