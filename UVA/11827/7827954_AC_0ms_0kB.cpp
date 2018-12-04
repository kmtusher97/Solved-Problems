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
#include <list>

using namespace std;

#define LL long long
#define uLL unsigned long long
#define DD double
#define LDD long double
#define PI acos(-1)
#define modulo 40000
#define MX 5000000
#define EPS 1e-9

//int dx4[] = { 0, 0, 1, -1 };
//int dy4[] = { 1, -1, 0, 0 };
//int dx8[] = { 0, 0, 1, -1, -1, 1, 1, -1 };
//int dy8[] = { 1, -1, 0, 0, -1, 1, -1, 1 };

vector<int> all_gcd;

int gcd(int a, int b)
{
    if(a%b == 0) return b;
    return gcd(b, a%b);
}

main()
{
    //freopen("INPUT.txt", "r", stdin);
    //freopen("OUTPUT.txt", "w", stdout);

    //cout << gcd(12, 4);
    string line;
    int cases, caseno=0, arr[110], i, j, n, num;
    scanf("%d", &cases);
    getchar();
    while( cases-- ) {
        getline(cin, line);
        stringstream ss(line);
        n = 0;
        while( ss >> num ) {
            arr[n++] = num;
        }
        all_gcd.clear();
        for(i=0; i<n-1; i++) {
            for(j=i+1; j<n; j++) {
                all_gcd.push_back( gcd(arr[i], arr[j]) );
            }
        }
        printf("%d\n", *max_element(all_gcd.begin(), all_gcd.end()) );
    }
}
