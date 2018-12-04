#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    int t, tc=0;
    long long n, x, y, a, b;         // declaration
   // scanf("%d", &t);        // number of test cases
    while( scanf("%lld", &n) && n ) {
        a=sqrt(n);      // square root of n
        // if n is a square number
        if(a*a==n) {
            if(a&1) y=a, x=1;      // if a is odd it's position is 1,y
            else x=a, y=1;             // if a is even it's position is x,1
        }
        else {
            b=a+1;                  // find nearest square number > n
            long  long nr_sq_num, mid;             // middle number of the sequence
            nr_sq_num=b*b, mid=nr_sq_num-a;     // ranges
            // if the number is between nearest square number and mid value
            if(n>=mid) {
                if(b&1) {
                    y=b;        // odd is for Y axis according to the pattern
                    x=(nr_sq_num-n)+1;     // the point is rightward
                }
                else {
                    x=b;        // even is for X axis according to the pattern
                    y=(nr_sq_num-n)+1;    // the point is upward
                }
            }
            else {
                if(b&1) {
                    x=b;        // opposite
                    y=b-(mid-n);     // the point is right downward
                }
                else {
                    y=b;        // opposite
                    x=b-(mid-n);        // the point is up leftward
                }
            }
        }
 
        printf("%lld %lld\n", x, y);    // coordinate/position of the point
    }
 
 
    return 0;
}
 

