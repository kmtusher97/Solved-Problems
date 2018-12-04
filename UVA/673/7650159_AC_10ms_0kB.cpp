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

main()
{
    //freopen("text_input.txt", "r", stdin);
    //freopen("text_output.txt", "w", stdout);

    int tc;
    scanf("%d", &tc);
    getchar();
    while(tc--) {
        char s[130];
        gets(s);
        int L=strlen(s), i;
        vector<char> v;
        bool flg=true;

        for(i=0; i<L; i++) {
            if(s[i]=='(' || s[i]=='[')
                v.push_back(s[i]);
            else if(s[i]==')' || s[i]==']')
                if(!v.size()) { flg=false; break; }
            else if(s[i]==')' && v.back()=='(') v.pop_back();
            else if(s[i]==']' && v.back()=='[') v.pop_back();
            else { flg=false; break; }
        }

        if(v.size()) flg=false;

        if(flg) printf("Yes\n");
        else printf("No\n");
    }
}
