#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <climits>
#include <vector>

#define PI acos(-1)
#define i64 long long
#define ui64 unsigned long long
#define d64 double
#define dd64 long double
#define MX 10008

using namespace std;

struct STR {
    string name;
    int dd, mm, yy;
} date[105];

bool cmpr(STR a, STR b)
{
    if(a.yy != b.yy) return a.yy < b.yy;
    else {
        if(a.mm != b.mm) return a.mm < b.mm;
        else {
            if(a.dd != b.dd) return a.dd < b.dd;
        }
    }
}

main()
{
    //freopen("text_input.txt", "r", stdin);
    //freopen("text_output.txt", "w", stdout);

    int n, i;
    while(scanf("%d", &n)==1) {
        for(i=0; i<n; i++) {
            cin >> date[i].name;
            scanf("%d %d %d", &date[i].dd, &date[i].mm, &date[i].yy);
        }

        sort(date, date+n, cmpr);

        cout << date[n-1].name << endl << date[0].name << endl;
    }
}
