#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>

#define PL 100

using namespace std;
bool vis[PL+5];
vector<int> prims;
int counter[101];

void seive()
{
    int i, j, L=sqrt(PL);
    // first prim
    prims.push_back(2);

    for(i=3; i<=PL; i+=2)
        if(!vis[i]) {
            prims.push_back(i);
            for(j=i; j<=PL; j+=(i+i)) vis[j]=true;
        }
}

void prim_factor(int x)
{
    int i, Lim=sqrt(x);

    for(i=0; prims.at(i)<=Lim; i++)
        while(x%prims.at(i)==0) {
            counter[prims.at(i)]++;
            x/=prims.at(i);
        }

    if(x>1) counter[x]++;
}

void factors_of_factorial(int x)
{
    memset(counter, 0, sizeof(counter));

    int i;

    for(i=x; i>1; i--) {
        prim_factor(i);
    }
}

int main()
{
    seive();
    int n;

    while(scanf("%d", &n)==1) {
        if(!n) break;
        int i, j=0, arr[100];
        factors_of_factorial(n);

        printf("%3d! =", n);
        for(i=1; i<=100; i++) {
            if(counter[i]) {
                if(j++==15) {
                    printf("\n      ");
                    j=1;
                }
                printf("%3d", counter[i]);
            }

        }
        printf("\n");
    }

    return 0;
}
