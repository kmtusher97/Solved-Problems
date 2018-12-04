#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main()
{
    //freopen("textinput.txt", "r", stdin);
    //freopen("textoutput.txt", "w", stdout);

    int t, tc=0;
    scanf("%d", &t);

    while(t--) {
        int n, k;
        scanf("%d", &n);
        int arr[n], rang[n], i, j=1, mx;

        for(i=0; i<n; ++i) {
            scanf("%d", &arr[i]);
            if(i==0) mx=arr[i], rang[0]=mx;
            else {
                int a=abs(arr[i]-arr[i-1]);
                mx=max(mx, a);
                rang[j++]=a;
            }
        }

        bool flg=true;
        for(i=0, k=mx; i<j; ++i) {
            if(mx==rang[i]) mx--;
            else if(flg && mx<rang[i]) {
                k++;
                flg=false;
            }
        }

        printf("Case %d: %d\n", ++tc, k);

    }
    return 0;
}
