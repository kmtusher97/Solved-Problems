/*294 - Divisors*/
#include <bits/stdc++.h>
#define MX 32000
using namespace std;
bool vis[MX+10];
int prime[10000], i, j, L;

void seive()
{
    prime[0]=2, L=1;

    for(i=3; i<MX; i+=2)
        if(!vis[i]) {
            prime[L++]=i;

            for(j=i*i; j<MX; j+=(i+i)) vis[j]=true;
        }

}

int number_of_divisors(int x)
{
    int num_of_div=1, div;

    for(i=0; i<L && prime[i]*prime[i]<=x; i++)
        if(x%prime[i]==0) {
            div=0;
            while(x%prime[i]==0) {
                div++;
                x/=prime[i];
            }

            num_of_div*=(++div);
        }

    if(x>1) num_of_div*=2;

    return num_of_div;
}

int main()
{
    seive();

    int TC, U, R, mx, D, M;

    scanf("%d", &TC);

    while(TC--) {
        scanf("%d%d", &U, &R);
        mx = number_of_divisors(U), M=U;

        for(j=U+1; j<=R; j++) {
            D = number_of_divisors(j);
            if(D>mx) mx=D, M=j;
        }

        printf("Between %d and %d, %d has a maximum of %d divisors.\n", U, R, M, mx);
    }


    return 0;
}
