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

main()
{
    //freopen("text_input.txt", "r", stdin);
    //freopen("text_output.txt", "w", stdout);

    int n, mx=11, mn=0;
    bool flg=true;
    string s;
    while(scanf("%d", &n) == 1 && n) {
        getchar();
        getline(cin, s);

        if(s == "too high") {
            if(n <= mn) flg=false;
            else mx=min(mx, n);
        }
        else if(s=="too low") {
            if(n >= mx) flg=false;
            else mn=max(mn, n);
        }
        else if(s == "right on") {
            if(n >= mx || n <= mn) flg=false;

            if(flg) printf("Stan may be honest\n");
            else printf("Stan is dishonest\n");
            mn=0, mx=11, flg=true;
        }
    }
}
