/*583 - Prime Factors*/
#include <iostream>
#include <cstdio>
#include <cmath>
#define SIZE 46500
using namespace std;
bool prime[SIZE];

void sieve()
{
    int i, j;

    prime[0]=prime[1]=1;

    for(i=4; i<SIZE; i+=2)
        prime[i] = 1;

    for(i=3; i<=sqrt(SIZE); i++)
        if(!prime[i]) {
            for(j=i; i*j<SIZE; j++)
                prime[i*j] = 1;
        }

}

int main()
{
    sieve();

    int N, f;

    while(scanf("%d", &N)) {
        if(N == 0) break;
        if(N < 0) {
            printf("%d = -1 x ", N);
            N *= -1;
        }
        else printf("%d = ", N);

        int i, L = 0, check = 0, R = sqrt(N), M = 1, x = N;

        for(i=2; i<=R; i++) {
            if(check) break;
            if(!prime[i]) {
                while(N%i == 0) {
                    printf("%d", i);
                    N /= i;
                    M *= i;

                    if(N > 1) printf(" x ");

                    if(M == x) {
                        check = 1;
                        break;
                    }
                }
            }
        }

        if(N > 1) printf("%d\n", N);
        else printf("\n");

    }

    return 0;
}
