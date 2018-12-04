#include<stdio.h>
int main()
{
    int t, i;
    double a,b,s,m,n,ans;
    scanf("%d",&t);
    for(i=1;i<=t;i++)
    {
       scanf("%lf%lf%lf",&a,&b,&s);
       if(1<=a&&b<=10&&1<=s<=1000)
        {
            m=a-((a+b)/3);
            n=b-((a+b)/3);
            ans=(m*s)/(m+n);
        }
        printf("%.0lf\n",ans);
    }
    return 0;
}
