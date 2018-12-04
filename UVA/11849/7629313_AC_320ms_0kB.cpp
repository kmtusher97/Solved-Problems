// practice
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <climits>

#define ll long long
#define ull unsigned long long
#define dd double
#define ldd long double
#define MX 1000000

using namespace std;

int Binary_search(int arr[], int x, int low, int high)
{
    if(high < low) return -1;
    int mid=low + (high-low)/2;

    if(arr[mid]==x) return 1;
    if(arr[mid]>x) {
        return Binary_search(arr, x, low, mid-1);
    }
    else if(arr[mid]<x) {
        return Binary_search(arr, x, mid+1, high);
    }
}

main()
{
    //freopen("text_input.txt", "r", stdin);
    //freopen("text_output.txt", "w", stdout);
    int n, m;
    while(scanf("%d%d", &n, &m)==2) {
        if(!n && !m) break;
        int arr[n], arr1[m], i, j;

        for(i=0; i<n; i++)
            scanf("%d", &arr[i]);

        for(i=0; i<m; i++)
            scanf("%d", &arr1[i]);

        int cnt=0;

        if(n<m) {
            for(i=0; i<n; i++) {
                if(Binary_search(arr1, arr[i], 0, m-1)==1) cnt++;
            }
        }
        else {
            for(i=0; i<m; i++) {
                if(Binary_search(arr, arr1[i], 0, n-1)==1) cnt++;
            }
        }

        printf("%d\n", cnt);
    }
}
