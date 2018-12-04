// practice
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
#define MX 1000000000

using namespace std;
char vis[MX+1];

main()
{
    //freopen("text_input.txt", "r", stdin);
    //freopen("text_output.txt", "w", stdout);
    int n, m;
    while(scanf("%d%d", &n, &m)==2) {
        if(!n && !m) break;
        int arr[n], arr1[m], i, j, cnt=0;

        for(i=0; i<n; i++) {
            scanf("%d", &arr[i]);
            vis[arr[i]]='0';
        }

        for(i=0; i<m; i++) {
            scanf("%d", &arr1[i]);
            if(vis[arr1[i]]=='0') {
                cnt++;
                vis[arr1[i]]=='\0';
            }
        }

        for(i=0; i<n; i++) {
            vis[arr[i]]='\0';
        }

        printf("%d\n", cnt);
    }
}
