#include <iostream>
#include <cstdio>
#include <cmath>
#define MX 1010
using namespace std;
bool vis[MX];
int prime[200], p;

void seive()
{
    int i, j;

    prime[1] = 1;
    prime[2] = 2;
    p = 3;

    for(i=3; i<MX; i+=2)
        if(!vis[i]) {
            prime[p++] = i;
            for(j=i; i*j<MX; j++)
                vis[i*j] = true;
        }

}

int binarySearch(int x)
{
    int mid, low = 1, high = p - 1, c = 0;

    while(low <= high) {
        mid = (low + high) / 2;

        if(prime[mid] == x) {
            return mid;
        }
        else if(prime[mid] < x && prime[mid + 1] > x) {
            return mid;
        }

        if(prime[mid] < x  && prime[mid + 1] <= x) {
            low = mid + 1;
        }

        if(prime[mid] > x) {
            high = mid - 1;
        }
    }
}

int main()
{
    seive();

    int N, C, L, i, mid, low, high;

    while(cin >> N >> C) {
        L = binarySearch(N);

        printf("%d %d: ", N, C);

        if(L < (2*C)) {
            low = 1;
            high = L;
        }
        else {
            if(L % 2 == 0) {
                mid = L / 2;
                low = mid - (C - 1);
                high = mid + C;
            }
            else {
                mid = L / 2;
                mid++;
                C--;
                low = mid - C;
                high = mid + C;
            }
        }

        for(i=low; i<=high; i++) {
            printf("%d", prime[i]);
            if(i != high) printf(" ");
            if(i == high) printf("\n");
        }

        printf("\n");
    }


    return 0;
}
