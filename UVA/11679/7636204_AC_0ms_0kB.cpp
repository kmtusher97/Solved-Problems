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
#define PI acos(-1)

using namespace std;

struct STR {
    int D, C, V;
};

int Binary_search(int arr[], int x, int low, int high)
{
    if(low > high) return -1;

    int mid=low+((high-low)/2);
    if(arr[mid]==x) return mid;
    if(arr[mid]>x) Binary_search(arr, x, low, mid-1);
    else Binary_search(arr, x, mid+1, high);
}

main()
{
    //freopen("text_input.txt", "r", stdin);
    //freopen("text_output.txt", "w", stdout);

    int B, N;
    while(scanf("%d%d", &B, &N)==2 && B && N) {
        int b[B], i;
        bool chk=true;
        STR n[N];

        for(i=0; i<B; i++) {
            scanf("%d", &b[i]);
        }

        for(i=0; i<N; i++) {
            scanf("%d%d%d", &n[i].D, &n[i].C, &n[i].V);
            b[n[i].D-1]-=n[i].V;
            b[n[i].C-1]+=n[i].V;
        }

        for(i=0; i<B; i++)
            if(b[i]<0) {
                chk=false;
                break;
            }

        if(chk) printf("S\n");
        else printf("N\n");
    }
}
