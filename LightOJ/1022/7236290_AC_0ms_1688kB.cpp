/*
*************************
      _dark_knight
*************************
    Light OJ problem 1022
*/
#include <bits/stdc++.h>
using namespace std;
double pi=2*acos(0.0);

int main()
{
    int T, TC=0;

    scanf("%d", &T);

    while(T--) {
        double r, sq, cir;

        scanf("%lf", &r);

        sq=4.0*r*r;
        cir=pi*r*r;

        printf("Case %d: %.2lf\n", ++TC, sq-cir);
    }

    return 0;
}
