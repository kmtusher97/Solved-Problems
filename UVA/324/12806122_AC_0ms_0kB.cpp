/*
    UVa problem 324 - Factorial Frequencies
*/
#include <bits/stdc++.h>
#define MX 800
#define high 368
using namespace std;
int F[high][MX];       // the list of all factorials 0-366
int freq[10];        // for storing the frequency of 0-9

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

void frequency(int x)      // function to find the frequency of 0-9
{
    memset(freq, 0, sizeof(freq));    // initializing all indexes of freq[] with 0
    int i, j;
    bool leading_0s=true;    // for leading zeros

    for(i=MX-1; i>=0; i--) {
        if(F[x][i]) leading_0s=false;
        if(!leading_0s) freq[F[x][i]]++;  // count the frequency of 0-9
    }
}

int main()
{
    factorial();
    int n;
    while(scanf("%d", &n)==1) {   // get the input
        frequency(n);
        printf("%d! --\n", n);
        printf("    (0) %d (1) %d (2) %d (3) %d (4) %d\n", freq[0], freq[1], freq[2], freq[3], freq[4]);
        printf("    (5) %d (6) %d (7) %d (8) %d (9) %d\n", freq[5], freq[6], freq[7], freq[8], freq[9]);
    }

    return 0;
}
