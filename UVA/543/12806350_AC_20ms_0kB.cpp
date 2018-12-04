/*543 - Goldbach's Conjecture*/
#include <iostream>
#include <cstdio>
#include <cmath>

#define SIZE 1000000
using namespace std;

int prime[SIZE];

void sieve()
{
    int i, j;

    for(i=0; i<SIZE; i++)
        prime[i] = 1;

    for(i=2; i<SIZE; i+=2)
        prime[i] = 0;

    for(i=3; i<sqrt(SIZE); i++)
        if(prime[i] == 1) {
            for(j=i; i*j<SIZE; j++)
                prime[i*j] = 0;
        }

}


int main()
{
    long n, i, x;

    sieve();

    prime[2] = 1;

    while(scanf("%ld", &n) && n) {
        x = 0;

        for(i=2; i<=n/2; i++) {

            if(prime[i] && prime[n-i]) {
                printf("%ld = %ld + %ld\n", n, i, n-i);
                x = 1;
            }
            if(x == 1) break;
        }

    }


    return 0;
}
