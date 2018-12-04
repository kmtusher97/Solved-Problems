/*573 - The Snail*/
#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    double H, U, D, F;
    while(scanf("%lf%lf%lf%lf", &H, &U, &D, &F) == 4 && H && U && D && F)
    {
        int day=0, t=0;
        double h=0, u, f=(F*U)/100.0;

        while(true) {
            day++;
            h += U;
            if(h > H) break;
            h -= D;
            if(h >= H || h < 0.00) break;
            if(U > 0.00) U -= f;
            else U = 0.0;
        }

        if(h >= H) printf("success on day %d\n", day);
        else printf("failure on day %d\n", day);
    }

    return 0;
}
