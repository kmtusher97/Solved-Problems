#include<bits/stdc++.h>
using namespace std;
int main()
{
 int a,b,c,no=1;

 while(scanf("%d%d%d",&a,&b,&c)==3)
 {
     int aa[a+5] ,bb[b+5],f[a+5],id,sum=0,max=0;

     if(a==0&&b==0&&c==0)break;
     for(int i=0;i<a;i++)
        cin>>aa[i];
     for(int i=0;i<b;i++)
        cin>>bb[i];
    memset(f,0,sizeof(aa));
    printf("Sequence %d\n",no++);
     for(int i=0;i<b;i++)
     {
         sum=0;
         id=bb[i]-1;
         if(f[id]==0)f[id]=1;
         else f[id]=0;
      for(int j=0;j<a;j++)
        {
            if(f[j]==1){
                sum+=aa[j];
            }
        }
        if(sum>max)max=sum;
         if(sum>c)break;
         }
     if(max>c)printf("Fuse was blown.\n");
     else{
        printf("Fuse was not blown.\n");
        printf("Maximal power consumption was %d amperes.\n",max);
     }
     printf("\n");
 }

return 0;
}
