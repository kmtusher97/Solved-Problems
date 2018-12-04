#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <climits>
#include <vector>

#define PI acos(-1)
#define i64 long long
#define ui64 unsigned long long
#define d64 double
#define dd64 long double
#define MX 100000

using namespace std;

string s;

struct STR { string a, b; } dic[MX+2];

bool cmpre(STR x, STR y)
{
    if(x.b != y.b) return x.b < y.b;
    return x.a < y.a;
}

int binarySearch(int low, int high)
{
    int mid;

    while(low <= high) {
        mid=low+(high-low)/2;
        if(dic[mid].b == s) return mid;
        else if(dic[mid].b > s) high=mid-1;
        else low=mid+1;
    }

    return -1;
}

main()
{
    //freopen("text_input.txt", "r", stdin);
    //freopen("text_output.txt", "w", stdout);

    int i=0, j, p;

    while(getline(cin, s)) {
        if(!s.size()) break;
        stringstream ss;
        ss << s;
        ss >> dic[i].a >> dic[i].b;
        i++;
    }

    sort(dic, dic+i, cmpre);

    while(getline(cin, s)) {
        if(!s.size()) break;
        p=binarySearch(0, i-1);

        if(p == -1) cout << "eh" << endl;
        else cout << dic[p].a << endl;
    }
}
