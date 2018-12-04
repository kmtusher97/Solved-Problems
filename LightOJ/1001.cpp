#include <bits/stdc++.h>
using namespace std;

int main() {
        int cases, caseno = 0, n;
        scanf("%d", &cases);
        while( cases-- ) {
                scanf("%d", &n);
                n >= 10 ? printf("10 %d\n", n-10) : printf("%d 0\n", n);
        }

        return 0;
}
