/*use C++(g++ 4.3.2) compiler*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    int TC, T = 1;
    long long N, n;
    scanf("%d", &TC);
    while (TC--) {
        scanf("%lld", &N);
        n = sqrt(N);
        n*=n;
        if (n == N) printf("Case %d: Yes\n", T++);
        else printf("Case %d: No\n", T++);
     }
    return 0;
}

