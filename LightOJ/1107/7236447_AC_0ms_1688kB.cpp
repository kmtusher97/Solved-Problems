/*
*************************
      _dark_knight
*************************
    Light OJ problem 1107
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T, TC=0;
    scanf("%d", &T);

    while(T--) {
        int x1, y1, x2, y2, x, y, N;
        // boundaries
        scanf("%d%d%d%d%d", &x1, &y1, &x2, &y2, &N);

        printf("Case %d:\n", ++TC);
        while(N--) {
            scanf("%d%d", &x, &y);
            if((x>=x1 && x<=x2) && (y>=y1 && y<=y2)) printf("Yes\n");
            else printf("No\n");
        }
    }


    return 0;
}
