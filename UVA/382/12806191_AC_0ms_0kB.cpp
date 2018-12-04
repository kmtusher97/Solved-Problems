#include <stdio.h>

int size=110, size1=5;

void spacePrinting(int number)
{
    int digit, i=0;
    char string[size1];
    while(number) { digit = number%10, number/=10, i++; }
    int j=size1-i, k;
    for(k=0; k<j; k++) { string[k]=' '; printf("%c", string[k]); }
}

int main()
{
    int N=0, ara[size];
    while(scanf("%d", &ara[N]) && ara[N]!=0)
        N++;
    printf("PERFECTION OUTPUT\n");
    int i;
    for(i=0; i<N; i++) {
        int n=ara[i];
        int j, sum=0;
        for(j=1; j<n; j++) {
            if(n%j==0) sum+=j;
        }
        if(sum==n) {
            spacePrinting(n);
            printf("%d  PERFECT\n", n);
        }
        else if(sum>n) {
            spacePrinting(n);
            printf("%d  ABUNDANT\n", n);
        }
        else {
            spacePrinting(n);
            printf("%d  DEFICIENT\n", n);
        }
    }
    printf("END OF OUTPUT\n");

    return 0;
}

