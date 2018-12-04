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

    string line, s;
    int tc, t=1;
    scanf("%d", &tc);
    getchar();
    while(tc--) {
        getchar();
        int v[5000], i=0, j=0;
        string v1[5000];
        getline(cin, line);
        stringstream ss;
        ss << line;
        while(ss >> v[i])
            i++;
        getline(cin, line);
        ss.clear();
        ss << line;
        j=0;
        while(ss >> v1[v[j]])
            j++;

        for(j=1; j<=i; j++)
            cout << v1[j] << endl;

        if(tc) cout << endl;
    }
}
