/*369 - Combinations*/
#include <stdio.h>

double factorial(int x)
{
    double f = 1, i;
    for(i=1; i<=x; i++)
        f *= i;
    return f;
}

int main()
{
    int N, M;
    while(scanf("%d%d", &N, &M) == 2 && N != 0 && M != 0) {
        printf("%d things taken %d at a time is %.0lf exactly.\n", N, M, factorial(N)/(factorial(M) * factorial(N-M)));
    }
    return 0;
}
