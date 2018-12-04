#include <bits/stdc++.h>
using namespace std;

// finding factorial
double factorial(int N, int p)
{
    long double f=1;

    for(int i=N; i>p; i--)
        f*=i;

    return f;
}

int main()
{
    int n, r, nr;

    while(scanf("%d%d", &n, &r)==2) {
        if(!n && !r) break;
        if(n>=r)
        {
            nr=n-r;
            int mx, mn, ans;
            mx=max(nr, r);
            mn=min(nr, r);

            ans=factorial(n, mx)/factorial(mn, 1);

            printf("%d\n", ans);
        }
    }



    return 0;
}
