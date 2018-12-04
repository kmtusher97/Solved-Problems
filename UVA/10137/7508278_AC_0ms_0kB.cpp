#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main()
{
    //freopen("textinput.txt", "r", stdin);
    //freopen("textoutput.txt", "w", stdout);

    int n;
    while(scanf("%d", &n)==1)
    {
        if(!n) break;
        double arr[n], avg, sum=0.0;
        int i;

        for(i=0; i<n; ++i) {
            scanf("%lf", &arr[i]);
            sum+=arr[i];
        }
        avg=sum/(n*1.0);
        double m1=0.0, m2=0.0, ans;

        for(i=0; i<n; ++i) {
            double a=arr[i]-avg;
            a*=100;
            a=(int)a/100.0;
            if(a>0.0) m1+=a;
            else m2-=a;
        }
        ans=max(m1, m2);
        printf("$%0.2lf\n", ans);
    }

    return 0;
}

