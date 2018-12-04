#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int i, j;
    while(scanf("%d%d", &i, &j) != EOF) {
        int x, y, k, mx=0;
        if(i>j) x=j, y=i;
        else x=i, y=j;

        for(k=x; k<=y; k++) {
            int cont = 0, n = k;
            while(n != 1) {
                cont++;
                if(n&1)
                    n=(3*n)+1;
                else
                    n/=2;
            }
            if(cont > mx)
                mx = cont;
        }

        printf("%d %d %d\n", i, j, mx+1);
    }

    return 0;
}
