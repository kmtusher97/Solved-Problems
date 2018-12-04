#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>

#define MX 31650
using namespace std;
bool vis[MX+5];
int prim[10000], p;

void seive()
{
    int i, j;

    prim[0]=2, p=1;

    for(i=3; i<=MX; i+=2)
        if(!vis[i]) {
            prim[p++]=i;
            for(j=i; j<=MX; j+=(i+i)) vis[j]=true;
        }

}

void f1(int n)
{
    int i, j, lim=sqrt(n);
    double x=n*1.0;

    for(i=0; i<p && prim[i]<=lim; i++)
        if(n%prim[i]==0) {
            double a=prim[i]*1.0;
            x*=(a-1);
            x/=a;
            while(n%prim[i]==0) {
                n/=prim[i];
            }
        }

    if(n>1) {
        x*=(n-1);
        x/=n;
    }

    printf("%.0lf\n", x);
}

int main()
{
    seive();

    int n;
    while(scanf("%d", &n)==1) {
        if(!n) break;

        f1(n);
    }

    return 0;
}
