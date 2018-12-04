#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <climits>
#include <algorithm>
#include <vector>
#include <map>


#define i64 long long
#define i64u unsigned long long
#define d64 double
#define ld64 long double
#define pi acos(-1)

using namespace std;

main()
{
    map<string, i64> mp;
    i64 dvlu, salary=0;
    int n, m;
    scanf("%d%d", &n, &m);
    getchar();

    string line, word;
    while(n--) {
        getline(cin, line);
        stringstream ss(line);
        ss >> word >> dvlu;
        mp[word] = dvlu;
    }

    while(m--) {
        salary=0;
        while(cin >> word, word != ".") {
            if(mp.find(word) != mp.end()) {
                salary += mp[word];
            }
        }
        cout << salary << endl;
    }

}
