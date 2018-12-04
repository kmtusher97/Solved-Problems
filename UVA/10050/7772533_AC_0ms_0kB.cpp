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

using namespace std;

#define LL long long
#define uLL unsigned long long
#define DD double
#define LDD long double
#define PI acso(-1)
#define modulo 1000003
#define MX 1000000
#define EPS 1e-9

main()
{
    int n, d, p, h;
    cin >> n;
    while(n--)
    {
        cin >> d >> p;
        int day[d+5], i, j, cnt=0;
        memset(day, 0, sizeof(day));

        while(p--)
        {
            cin >> h;
            for(i=h; i<=d; i+=h) {
                day[i]++;
            }
        }

        for(i=1; i<=d; i++) {
            if(day[i]) cnt++;
        }
        for(j=6; j<=d; j+=7) {
            if(day[j]) cnt--;
            if(day[j+1]) cnt--;
        }

        cout << cnt << endl;
    }
}
