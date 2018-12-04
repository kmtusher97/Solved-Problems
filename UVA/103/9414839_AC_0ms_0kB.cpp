#include <bits/stdc++.h>
using namespace std;

int n, d;
struct data {
        int dmnsn[12], indx;
} boxes[34];

bool isGretr( int x, int y ) {
        for(int i=0; i<d; i++) if( boxes[x].dmnsn[i] <= boxes[y].dmnsn[i] ) {
                return false;
        }

        return true;
}

void LIS() {
        int lis[34], lnth=1, pre;
        for(int i=0; i<=n; i++) lis[i]=1;

        for(int i=0; i<n; i++) {
                for(int j=i+1; j<n; j++) {
                        if( isGretr(j, i) && lis[j] < lis[i]+1 ) {
                                lis[j] = lis[i]+1;
                        }
                }
        }

        for(int i=0; i<n; i++) if( lnth <= lis[i] ) {
                lnth = lis[i], pre = i;
        }

        printf("%d\n", lnth);
        vector<int> v; v.push_back( boxes[pre].indx ), lnth--;

        for(int i=n-1; i>=0; i--) if( lis[i] == lnth && isGretr(pre, i) ) {
                v.push_back( boxes[i].indx ), pre = i, lnth--;
        }

        printf("%d", v[ v.size()-1 ]);
        for(int i=v.size()-2; i>=0; i--) printf(" %d", v[i]);
        printf("\n");
}

int main() {
        //freopen("OUTPUT.txt", "w", stdout);
        
        while( ~scanf("%d %d", &n, &d) ) {
                for(int i=0; i<n; i++) {
                        for(int j=0; j<d; j++) {
                                scanf("%d", &boxes[i].dmnsn[j]);
                        }
                        sort(boxes[i].dmnsn, boxes[i].dmnsn+d);
                        boxes[i].indx = i+1;
                }

                for(int i=0; i<n; i++) {
                        for(int j=i+1; j<n; j++) {
                                if( isGretr(i, j) ) swap( boxes[i], boxes[j] );
                        }
                }

                LIS();
        }

        return 0;
}
