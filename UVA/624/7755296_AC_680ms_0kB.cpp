#include <iostream>
#include <sstream>
#include <iomanip>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <climits>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

#define PI acos(-1)
#define i64 long long
#define ui64 unsigned long long
#define d64 double
#define ld64 long double
#define modulo 1000003
#define MX 1000002

main()
{
    int n, t, i, j, k, lim, m, cnt, pos=0, a;
    i64 sum=0, mx;

    while(scanf("%d%d", &n, &t)==2) {
        int arr[100], v[100], ans[100];

        for(i=0; i<t; i++) scanf("%d", &arr[i]);
        lim = (1<<t)-1;

        for(i=0, mx=-1; i<=lim; i++) {
            m=i, cnt=0, j=0, sum=0;
            while(m) {
                int mod=m%2;
                if(mod) {
                    sum+=arr[cnt];
                    v[j++]=arr[cnt];
                }
                m/=2;
                cnt++;
            }
            if(sum >= mx && sum <= n) {
                mx=sum;
                a=0;
                for(k=0; k<j; k++) ans[a++]=v[k];
            }
        }

        for(i=0; i<a; i++)
            printf("%d ", ans[i]);
        printf("sum:%d\n", mx);
    }
}
