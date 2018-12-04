#include <bits/stdc++.h>
#define ll long long
using namespace std;

long long ekka_dokka(ll x)
{
    if(x&1) return 0;

    while(x%2==0) {
        x/=2;
    }

    return x;
}

int main()
{
    int T, TC=0;

    scanf("%d", &T);

    while(T--) {
        ll N, ed;
        scanf("%lld", &N);

        ed=ekka_dokka(N);
        printf("Case %d: ", ++TC);
        if(!ed || ed==1) printf("Impossible\n");
        else printf("%lld %lld\n", ed, N/ed);
    }

    return 0;
}
