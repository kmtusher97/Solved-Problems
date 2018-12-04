/*
    UVa problem 12416 - Excessive Space Remover
*/
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <climits>
#include <vector>

#define ll long long
#define dd double
#define lldd long double
#define MX 2147483647

using namespace std;

main()
{
    //freopen("text_input.txt", "w", stdin);
    //freopen("text_output.txt", "w", stdout);

    char n1[1000], n2[1000];
    string sym;
    while(cin >> n1 >> sym >> n2) {
        cout << n1 << " " << sym << " " << n2 << endl;
        lldd x, y;
        x=atof(n1);
        y=atof(n2);

        if(x>MX) cout << "first number too big" << endl;
        if(y>MX) cout << "second number too big" << endl;
        if(sym=="+" && (x+y)>MX) cout << "result too big" << endl;
        if(sym=="*" && (x*y)>MX) cout << "result too big" << endl;
    }
}
