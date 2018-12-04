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

map<string, string> mp;

int main()
{
    //freopen("INPUT.txt", "r", stdin);
    //freopen("OUTPUT.txt", "w", stdout);

    int L, N, i;
    string s, a, b;
    while(scanf("%d%d", &L, &N)==2)
    {
        getchar();
        while(L--) {
            getline(cin, s);
            stringstream ss(s);
            ss >> a >> b;
            mp[a]=b;
        }
        while(N--) {
            cin >> s;
            if(mp.find(s) != mp.end()) {
                cout << mp[s] << endl;
            }
            else {
                int sz=s.size();
                char c, ch=s[sz-1];
                if(ch=='y') {
                    c=s[sz-2];
                    if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u')
                        s+="s";
                    else
                        s[sz-1]='i', s+="es";
                }
                else if(ch=='o' || ch=='s' || ch=='x' || (ch=='h' && (s[sz-2]=='c' || s[sz-2]=='s')) ) {
                    s+="es";
                }
                else s+="s";

                cout << s << endl;
            }
        }
        mp.clear();
    }

    return 0;
}
