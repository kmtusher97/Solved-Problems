/*
    UVa problem 10880 - Colin and Ryan
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <vector>

#define ll long long
#define dd double
#define MX 100
#define MX1 5000
#define MX2 16000

using namespace std;

vector<int> v;

void divisor(int x)
{
    int i, lim=sqrt(x);

    for(i=2; i<=lim; i++)
        if(x%i==0) {
            v.push_back(i);
        }
}

main()
{
    //freopen("text_input.txt", "r", stdin);
    //freopen("text_output.txt", "w", stdout);

    int tc, t=0;
    scanf("%d", &tc);

    while(tc--) {
        int n;
        scanf("%d", &n);
        v.clear();
        divisor(n);
        int i, L=v.size();

        printf("Case #%d: %d = ", ++t, n);
        if(L>=2) {
            printf("%d * %d = %d * %d\n", v.at(0), n/v.at(0), v.at(1), n/v.at(1));
        }
        else if(L) {
            printf("%d * %d = %d * %d\n", v.at(0), n/v.at(0), v.at(0), n/v.at(0));
        }
    }
}
