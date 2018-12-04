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

map<char, char> mp1;
map<string, int> mp2;

main()
{
    //freopen("INPUT.txt", "r", stdin);
    //freopen("OUTPUT.txt", "w", stdout);

    /* mapping letters */
    mp1['A']=mp1['B']=mp1['C']='2';
    mp1['D']=mp1['E']=mp1['F']='3';
    mp1['G']=mp1['H']=mp1['I']='4';
    mp1['J']=mp1['K']=mp1['L']='5';
    mp1['M']=mp1['N']=mp1['O']='6';
    mp1['P']=mp1['R']=mp1['S']='7';
    mp1['T']=mp1['U']=mp1['V']='8';
    mp1['W']=mp1['X']=mp1['Y']='9';

    string s;
    int tc, n, i, j, sz;
    scanf("%d", &tc);
    while(tc--)
    {
        scanf("%d", &n);
        while(n--)
        {
            cin >> s;
            char arr[20];
            sz=s.size();

            for(i=0, j=0; i<sz; i++) {
                if(j==3) arr[j++]='-';
                if(s[i]>='A' && s[i]<'Z')
                    arr[j++]=mp1[s[i]];
                else if(s[i]>='0' && s[i]<='9')
                    arr[j++]=s[i];
            }
            arr[j]='\0';
            s=arr;

            if(mp2.find(s) != mp2.end()) mp2[s]++;
            else mp2[s]=1;
        }

        bool f=false;
        for(map<string, int> :: iterator it=mp2.begin(); it!=mp2.end(); it++)
        {
            if(it->second > 1) {
                f=true;
                cout << it->first << " " << it->second << endl;
            }
        }
        if(!f) cout << "No duplicates." << endl;
        if(tc) cout << endl;
        mp2.clear();
    }
}
