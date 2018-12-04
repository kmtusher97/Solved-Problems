#include <iostream>
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

    map<int, int> mp;
    string s;
    vector<int> v;
    int n, i, lim, t=0;

    while(getline(cin, s), s!="") {
        stringstream ss(s);

        while(ss >> n) {
            if(mp.find(n) != mp.end()) {
                mp[n]++;
            }
            else {
                mp[n] = 1;
                v.push_back(n);
            }
        }
    }

    lim = v.size();

    for(i=0; i<lim; i++) {
        cout << v.at(i) << " " << mp[v.at(i)] << endl;
    }
    //cout << endl;
}
