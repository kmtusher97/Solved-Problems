#include <iostream>
#include <climits>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    int n;
    while(scanf("%d", &n)==1 && n) {
        char img;
        int mx=INT_MIN, arr[n], i, c=0, m=n;

        while(m--) {
            getchar();
            int x=0;
            for(i=0; i<25; ++i) {
                scanf("%c", &img);
                if(img=='X') x++;
            }
            arr[c++]=x;
            mx=max(mx, x);
        }

        int sum=0;
        for(i=0; i<c; ++i) {
            sum+=(mx-arr[i]);
        }

        printf("%d\n", sum);
    }

    return 0;
}
