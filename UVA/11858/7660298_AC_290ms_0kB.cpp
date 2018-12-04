#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <climits>
#include <vector>

#define PI acos(-1)
#define i64 long long
#define ui64 unsigned long long
#define d64 double
#define dd64 long double

using namespace std;

i64 cnt;

void Merge(int arr[], int left, int mid, int right)
{
    int i, j, k;
    int n1 = mid-left+1;
    int n2 = right-mid;

    int temp1[n1], temp2[n2];

    for(i=left, j=0; i<=mid; i++) {
        temp1[j++]=arr[i];
    }
    for(i=mid+1, j=0; i<=right; i++) {
        temp2[j++]=arr[i];
    }

    i=0, j=0, k=left;

    while(i<n1 && j<n2) {
        if(temp1[i] < temp2[j]) {
            arr[k++] = temp1[i++];

        }
        else {
            arr[k++] = temp2[j++];
            cnt+=n1-i;
        }
    }

    while(i < n1) {
        arr[k++] = temp1[i++];
    }

    while(j < n2) {
        arr[k++] = temp2[j++];
    }
}

void Merge_Sort(int arr[], int left, int right)
{
    if(left < right) {
        int mid = left + (right-left)/2;

        Merge_Sort(arr, left, mid);
        Merge_Sort(arr, mid+1, right);

        Merge(arr, left, mid, right);
    }
}

main()
{
    //freopen("text_input.txt", "r", stdin);
    //freopen("text_output.txt", "w", stdout);

    int n;
    while(scanf("%d", &n)==1) {
        cnt=0;
        int i, arr[n];
        /* get the array */
        for(i=0; i<n; i++)
            scanf("%d", &arr[i]);

        Merge_Sort(arr, 0, n-1);
        printf("%lld\n", cnt);
    }
}
