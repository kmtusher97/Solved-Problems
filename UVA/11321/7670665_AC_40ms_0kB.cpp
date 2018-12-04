#include <iostream>
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
#define MX 10008

using namespace std;

struct STR
{
    int num, mod;
} arr[MX+5];

bool cmpre(STR a, STR b)
{
    if( a.mod!=b.mod ) return a.mod < b.mod;
    else if( a.mod==b.mod )
    {
        if( (a.num%2!=0 && b.num%2==0 ) ) return true;
        else if( (b.num%2!=0 && a.num%2==0 ) ) return false;
        else if( a.num%2!=0 && b.num!=0 ) return a.num > b.num;
        else return a.num < b.num;
    }
}

int main()
{
    //freopen("text_input.txt", "r", stdin);
    //freopen("text_output.txt", "w", stdout);

    int n, m, i, j;
    while(scanf("%d%d", &n, &m)==2)
    {
        if(!n && !m)
        {
            printf("%d %d\n", n, m);
            break;
        }
        for(i=0; i<n; i++)
        {
            scanf("%d", &arr[i].num);
            if(m) arr[i].mod=arr[i].num%m;
            else arr[i].mod=0;
        }
        sort(arr, arr+n, cmpre);

        printf("%d %d\n", n, m);

        for(j=0; j<n; j++)
            printf("%d\n", arr[j].num);
    }
    return 0;
}
