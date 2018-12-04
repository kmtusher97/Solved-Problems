/*
    UVa problem 568 - Just the Facts
*/
#include <bits/stdc++.h>
#define MX 10000
#define high 10005
using namespace std;
int F[high][MX];       // the list of all factorials 0-366

void factorial()   // function to find list F[][]
{
    F[0][0]=1;    // as 0! = 1;
    int i, j, d, carry=0;

    for(i=1; i<high; i++)   // starting from 1
        for(j=0, carry=0; j<MX; j++) {
            d=(F[i-1][j]*i+carry);      // multiplying i with (i-1)!
            carry=d/10;                 // the carry
            F[i][j]=d%10;               // storing in the F list
        }
}

int last_non0_element(int x)        // function to find the last non 0 element
{
    for(int i=0; i<MX; i++)
        if(F[x][i])
            return F[x][i];

}

int main()
{
    factorial();
    int n;
    while(scanf("%d", &n)==1) {   // get the input
        printf("%5d -> %d\n", n, last_non0_element(n));
    }

    return 0;
}
