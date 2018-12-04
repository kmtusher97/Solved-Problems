// UVA 10062 - Tell me the frequencies!
#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <vector>

#define ll long long
#define ull unsigned long long
#define dd double
#define ldd long double

using namespace std;

struct STR {
    int ascii, freq;
} F[130];

bool cmp(STR a, STR b)
{
    if(a.freq != b.freq) return a.freq < b.freq;
    return a.ascii > b.ascii;
}

main()
{
    //freopen("file_input.txt", "r", stdin);
    //freopen("file_output.txt", "w", stdout);

    string s;
    int t=0;
    while(getline(cin, s)) {
        if(t++) cout << endl;
        int i, L=s.size();
        memset(F, 0, sizeof(F));
        for(i=0; i<L; i++) {
            F[s[i]].freq++;
            F[s[i]].ascii=s[i];
        }

        sort(F, F+130, cmp);

        for(i=0; i<130; i++) {
            if(F[i].freq)
                cout << F[i].ascii << " " << F[i].freq << endl;
        }
    }
}
