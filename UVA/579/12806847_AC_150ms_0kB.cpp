#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

int main()
{
    int hour, minite;
    char c;
    while(cin >> hour >> c >> minite) {
        if(hour == 0 && minite == 0) break;
        double h, m, a, b, angle;
        m = minite * 1.0;
        h = (hour * 5.0) + (m / 12.0);
        m = m * 6.0, h = h * 6.0;
        if(h < m) swap(h, m);
        a = h - m;
        b = 360 - a;
        if(b < a) angle = b;
        else angle = a;
        cout << fixed << setprecision (3) << angle << endl;
    }

    return 0;
}

