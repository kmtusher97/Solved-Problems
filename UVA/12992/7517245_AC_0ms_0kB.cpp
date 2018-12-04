#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    //freopen("file2.txt", "r", stdin);
    //freopen("file3.txt", "w", stdout);

    int t, tc=0;
    scanf("%d", &t);

    while(t--) {
        int n;
        scanf("%d", &n);
        printf("Case #%d: %d\n", ++tc, n+(n-1));
    }

    return 0;
}
