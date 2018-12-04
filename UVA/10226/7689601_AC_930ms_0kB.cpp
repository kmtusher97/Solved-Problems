#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <climits>
#include <vector>
#include <map>

#define PI acos(-1)
#define i64 long long
#define ui64 unsigned long long
#define d64 double
#define dd64 long double
#define MX 32000

using namespace std;

main()
{
    //freopen("text_input.txt", "r", stdin);
    //freopen("text_output.txt", "w", stdout);

    map<string, d64> mp;
    string line, tree;
    int tc, i=0;
    d64 total, per;

    scanf("%d", &tc);
    getchar();
    getline(cin, line);

    while(tc--) {
        total = 0;
        while(getline(cin, line), line != "") {
            total++;
            if(mp.find(line) != mp.end()) mp[line]++;
            else mp[line] = 1;
        }

        if(i++) cout << endl;

        for(map<string, d64> :: iterator it = mp.begin(); it != mp.end(); it++) {
            cout << it->first << " ";
            per = it->second;
            per = (per/total) * 100.0;
            cout << setprecision(4) << fixed << per << endl;
        }

        mp.clear();
    }
}
