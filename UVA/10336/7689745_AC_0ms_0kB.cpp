#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <climits>
#include <vector>
#include <map>

#define PI acos(-1)
#define i64 long long
#define ui64 unsigned long long
#define d64 double
#define dd64 long double
#define MX 32000

using namespace std;

char land[1000][1000];
int dx[4] = { 0, 0, 1, -1 }, dy[4] = { 1, -1, 0, 0};

struct STR{
    char L;
    int num;
} arr[128];

bool cmp(STR x, STR y)
{
    if(x.num != y.num) return x.num > y.num;
    return x.L < y.L;
}

void vis_matrix(int i, int j, int r, int c, char ch)
{
    land[i][j]='.';
    int a, b, k;

    for(k=0; k<4; k++) {
        a = i+dx[k];
        b = j+dy[k];

        if ((a>=0 && a<=r) && (b>=0 && b<=c) && land[a][b]==ch )  vis_matrix(a, b, r, c, ch);
    }

}

main()
{
    //freopen("text_input.txt", "r", stdin);
    //freopen("text_output.txt", "w", stdout);

    int tc, t=0, r, c, i, j, k;
    scanf("%d", &tc);
    while(tc--) {
        scanf("%d%d", &r, &c);
        for(i=0; i<r; i++)
            scanf("%s", land[i]);

        memset(arr, 0, sizeof(arr));

        for(i=0, k=0; i<r; i++) {
            for(j=0; j<c; j++) {
                if(land[i][j] >= 'a' && land[i][j] <= 'z') {
                    char c=land[i][j];
                    arr[c].L=c;
                    arr[c].num++;
                    vis_matrix(i, j, r-1, c-1, land[i][j]);
                    k++;
                }
            }
        }

        sort(arr+96, arr+125, cmp);

        printf("World #%d\n", ++t);

        for(i=96; i<124; i++) {
            if(arr[i].num)
                cout << arr[i].L << ": " << arr[i].num << endl;
        }

    }
}
