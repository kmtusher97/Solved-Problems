#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
using namespace std;

#define sc scanf
#define pf printf
#define eps 1e7

double area_trngle( double a, double b, double c ) { double s = (a+b+c)/2.0; return sqrt( s*(s-a)*(s-b)*(s-c) ); }

double bisection( double lo, double hi, double r, double AB ) {
        double mid;
        for(int i=0; i<120; i++) {
                mid = (lo+hi)/2.0;
                if( (mid/AB)*(mid/AB) > r ) hi = mid;
                else lo = mid;
        }
        return mid;
}

int main() {
        int cases, caseno = 0;
        double AB, AC, BC, ABC, ADE, rtio;
        sc("%d", &cases);
        while( cases-- ) {
                sc("%lf %lf %lf %lf", &AB, &AC, &BC, &rtio);
                ABC = area_trngle( AB, AC, BC );
                ADE = ( rtio*ABC ) / ( rtio+1.0 );
                pf("Case %d: %.10lf\n", ++caseno, bisection( 0, AB, ADE/ABC, AB ));
        }

        return 0;
}
