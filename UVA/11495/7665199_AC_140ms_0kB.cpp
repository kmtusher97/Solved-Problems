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
#define MX 1000000

using namespace std;

i64 cnt;
int arr[MX];

void merge_sort(int left, int right)
{
    if(left == right) return;
    int mid = left + (right-left)/2;

    merge_sort(left, mid);
    merge_sort(mid+1, right);

    //Merge(left, mid, right);

    int i, j, k;
    int n1=mid-left+1;
    int n2=right-mid;

    int temp1[n1], temp2[n2];

    for(i=left, k=0; i<=mid; i++)
        temp1[k++]=arr[i];
    for(i=mid+1, k=0; i<=right; i++)
        temp2[k++]=arr[i];

    for(i=0, j=0, k=left; i<n1 && j<n2; k++) {
        if(temp1[i] < temp2[j]) arr[k]=temp1[i++];
        else arr[k]=temp2[j++], cnt+=(n1-i);
    }

    while(i<n1) arr[k++]=temp1[i++];
    while(j<n2) arr[k++]=temp2[j++];
}

main()
{
    int i, n;
    while(scanf("%d", &n)==1 && n) {
        for(i=0; i<n; i++)
            scanf("%d", &arr[i]);
        cnt=0;
        merge_sort(0, n-1);

        if(cnt&1) printf("Marcelo\n");
        else printf("Carlos\n");
    }
}
