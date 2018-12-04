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
#define MX 1000000

using namespace std;

struct STR {
    int a, b;
};

char ans[MX+5];

main()
{
    //freopen("text_input.txt", "r", stdin);
    //freopen("text_output.txt", "w", stdout);

    int tc, t=0;
    scanf("%d", &tc);

    while(tc--) {
        if(t++) printf("\n");

        int n, i, j=0, carry=0;
        scanf("%d", &n);
        STR arr[n];

        for(i=0; i<n; i++)
            scanf("%d %d", &arr[i].a, &arr[i].b);

        for(i=n-1; i>=0; i--) {
            int d=(carry+arr[i].a+arr[i].b);
            ans[j++]=(d%10)+48;
            carry=d/10;
        }

        if(carry) ans[j++]=carry;

        ans[j]='\0';

        for(i=j-1; i>=0; i--)
            printf("%c", ans[i]);

        printf("\n");
    }
}
