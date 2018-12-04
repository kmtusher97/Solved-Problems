#include<bits/stdc++.h>
using namespace std;
char str[1000000];
int main()
{
    int l;
    while(gets(str))
    {
        l=strlen(str);
        if(l==0)continue;
        if(l==1){puts(str);continue;}
        for(int i=0;i<l;i++)
        {
            if(str[i]==32){printf(" ");continue;}
            if(i==l-1&&str[i-1]==32){putchar(str[l-1]);continue;}
            for(int j=i+1;j<l;j++)
            {
                if(str[j]==32||j==l-1)
                {
                    if(j==l-1)putchar(str[j]);
                    for(int k=j-1;k>=i;k--)
                        putchar(str[k]);
                    i=j-1;
                    break;
                }
            }
        }
        printf("\n");
    }

    return 0;
}
