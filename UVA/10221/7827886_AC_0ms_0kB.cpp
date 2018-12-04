#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <iomanip>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <list>

using namespace std;

#define LL long long
#define uLL unsigned long long
#define DD double
#define LDD long double
#define PI acos(-1)
#define modulo 40000
#define MX 5000000
#define EPS 1e-9

//int dx4[] = { 0, 0, 1, -1 };
//int dy4[] = { 1, -1, 0, 0 };
//int dx8[] = { 0, 0, 1, -1, -1, 1, 1, -1 };
//int dy8[] = { 1, -1, 0, 0, -1, 1, -1, 1 };

main()
{
    //freopen("INPUT.txt", "r", stdin);
    //freopen("OUTPUT.txt", "w", stdout);

    string line, angle_not;
    double R = 6440, dis, angle, r, s, c;
    while( getline(cin, line) ) {
        stringstream ss(line);
        ss >> dis >> angle >> angle_not;
        if( angle > 180 ) angle = 360 - angle;
        if( angle_not == "deg" ) {
            angle = (angle * PI) / 180.0;
        }
        else {
            angle/=60.0;
            angle = (angle * PI) / 180.0;
        }
        r = R+dis;
        s = r * angle;
        c = sqrt( (2*r*r) - (2*r*r*cos(angle)) );
        cout << setprecision(6) << fixed << s << " " << c << endl;
    }
}
