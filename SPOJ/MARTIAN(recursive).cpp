/*
************************************************
*           * KAMRUL HASAN TUSHER              *
*           * JAHANGIRNAGAR UNIVERSITY         *
*           * CSE-45                           *
************************************************
*/
#include <bits/stdc++.h>
using namespace std;

#define sc scanf
#define pf printf

int mtrx1[800][800], mtrx2[800][800], dp[800][800];

int ff( int i, int j ) {
        if( i < 1 || j < 1 ) return dp[i][j];
        if( dp[i][j] > 0 ) return dp[i][j];
        return dp[i][j] = max( mtrx2[i][j] + ff( i, j-1 ), mtrx1[i][j] + ff( i-1, j ) );
}

int main() {
        int r, c, i, j, a;
        while( sc("%d %d", &r, &c) == 2 ) {
                if( !r && !c ) break;
                for(i=1; i<=r; i++) {
                        for(j=1; j<=c; j++) {
                                sc("%d", &mtrx1[i][j]);
                                mtrx1[i][j] += mtrx1[i][j-1];
                        }
                }
                for(i=1; i<=r; i++) {
                        for(j=1; j<=c; j++) {
                                sc("%d", &mtrx2[i][j]);
                                mtrx2[i][j] += mtrx2[i-1][j];
                        }
                }
                memset(dp, 0, sizeof dp);
                pf("%d\n", ff(r, c));
        }

        return 0;
}
