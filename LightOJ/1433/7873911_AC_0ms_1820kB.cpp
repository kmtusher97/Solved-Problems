#include <iostream>
#include <cstdio>
#include <cmath>
#include <iomanip>

using namespace std;

#define PI acos(-1)

double Distance(double x1, double y1, double x2, double y2)
{
    double dis = sqrt( (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) );
    return dis;
}

main()
{
    int cases, caseno = 0;
    double ox, oy, ax, ay, bx, by, ab, oa, angle, arc;
    scanf("%d", &cases);
    while( cases-- ) {
        scanf("%lf %lf %lf %lf %lf %lf", &ox, &oy, &ax, &ay, &bx, &by);
        ab = Distance(ax, ay, bx, by);
        oa = Distance(ox, oy, ax, ay);
        angle = acos( 1 - ( (ab*ab) / (2*oa*oa) ) );
        arc = angle * oa;
        printf("Case %d: %lf\n", ++caseno, arc);
    }
}
