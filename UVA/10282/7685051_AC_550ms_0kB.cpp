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
    map<string, string> dictionary;
    string engword, forignword, line;

    while(getline(cin, line), line!="")
    {
        stringstream ss(line);
        ss >> engword >> forignword;

        dictionary[forignword] = engword;
    }

    while(getline(cin, line))
    {
        if(dictionary.find(line) == dictionary.end())
            cout << "eh" << endl;
        else
            cout << dictionary[line] << endl;
    }
}
