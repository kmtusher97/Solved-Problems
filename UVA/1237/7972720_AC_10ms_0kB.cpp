#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int t,d,i,j,q,n,co,f;
    scanf("%lld",&t);
    while(t--){
        scanf("%lld",&d);
        getchar();
        char a[d+5][25];
        long long int b[100000],c[100000];
        for(i=0;i<d;i++){
                scanf("%s",a[i]);
        getchar();
            scanf("%lld%lld",&b[i],&c[i]);
        }
        scanf("%lld",&q);
        for(j=1;j<=q;j++){
                scanf("%lld",&n);
                co=0;
            for(i=0;i<d;i++){
                if((n>=b[i])&&(n<=c[i])){
                    co=co+1;
                    if(co==1){
                        f=i;
                    }
                }
                if(co>1){
                    break;
                }
            }
            if(co==0){
                printf("UNDETERMINED\n");
            }
            else if(co==1){
                printf("%s\n",a[f]);
            }
            else if(co>1){
                printf("UNDETERMINED\n");
            }
        }
        if(t) printf("\n");
    }
    return 0;
}
