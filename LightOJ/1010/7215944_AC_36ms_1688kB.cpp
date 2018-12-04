/*
    * light OJ problem 1010
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, tc=0, m, n, n_o_ngt;
    //number of test case
    scanf("%d", &N);

    while(N--) {
        // grid
        scanf("%d%d", &m, &n);

        if(m==1 || n==1) n_o_ngt=m*n;
        else if(m==2) {
            int n1, a=n/2;
            if(n&1) n1=a+1;
            else {
                if(a&1) n1=a+1;
                else n1=a;
            }

            n_o_ngt=m*n1;
        }
        else if(n==2) {
            int m1, a=m/2;
            if(m&1) m1=a+1;
            else {
                if(a&1) m1=a+1;
                else m1=a;
            }

            n_o_ngt=n*m1;
        }
        else if(m&1 && n&1) {
            int a=m*n;
            n_o_ngt=(a/2)+1;
        }
        else n_o_ngt=(m*n)/2;

        printf("Case %d: %d\n", ++tc, n_o_ngt);
    }



    return 0;
}
