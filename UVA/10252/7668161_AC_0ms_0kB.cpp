#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <climits>

#define ll long long
#define ull unsigned long long
#define dd double
#define ldd long double
#define PI acos(-1)

using namespace std;

int ascii1[128], ascii2[128], i, j, L1, L2;
string a, b;

main()
{
    //freopen("text_input.txt", "r", stdin);
    //freopen("text_output.txt", "w", stdout);

    while(getline(cin, a)) {
        getline(cin, b);
        L1=a.size(), L2=b.size();

        memset(ascii1, 0, sizeof(ascii1));
        memset(ascii2, 0, sizeof(ascii2));


        for(i=0; i<L1; i++) {
            ascii1[a[i]]++;
        }
        for(i=0; i<L2; i++)
            ascii2[b[i]]++;

        for(i=97; i<124; i++) {
            while (ascii1[i] && ascii2[i]) {
                printf("%c", i);
                ascii1[i]--;
                ascii2[i]--;
            }
        }
        printf("\n");
    }
}
