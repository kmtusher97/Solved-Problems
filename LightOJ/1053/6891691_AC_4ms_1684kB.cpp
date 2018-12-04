#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int TC, T=1;
    cin >> TC;
    while(TC--) {
        double a, b, c, A, B, C;
        cin >> a >> b >> c;
        if((a < b+c) && (b < a+c) && (c < a+b)) {
            A = a*a;
            B = b*b;
            C = c*c;

            if((A == B+C) || (B == A+C) || (C == A+B)) cout << "Case " << T++ << ": yes" << endl;
            else cout << "Case " << T++ << ": no" << endl;
        }
    }

    return 0;
}
