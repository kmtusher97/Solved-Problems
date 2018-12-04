#include<bits/stdc++.h>
using namespace std;
#define max 100000
int ara[max];
void siv(int n)
{
    int sq=sqrt(n),id=0;

    for(int i=3; i<=sq+1; i++)
    {
        for(int j=i*i; j<=n; j+=(i+i)) //use brackets
        {
            ara[j]=1;
        }
    }
}
int main()
{
    char s[100];
    int l,sum;
    //freopen("C:\\Users\\Lab\\Desktop\\a.txt", "w", stdout);
    while(gets(s))
    {

        sum=0;
        siv(max);
        l=strlen(s);
        for(int i=0; i<l; i++)
        {
            if(s[i]>='a'&&s[i]<='z')
                sum+=s[i]-'a'+1;
            else if(s[i]>='A'&&s[i]<='Z') sum+=s[i]-'A'+27;
        }
        if(sum==0){
            cout<<"It is not a prime word."<<endl;
            continue;
        }
        if(sum==1 || sum == 2)
        {
            cout<<"It is a prime word."<<endl;
            continue;
        }
        //cout<<sum;
        if(ara[sum]==0&&sum%2==1)
            cout<<"It is a prime word."<<endl;
        else cout<<"It is not a prime word."<<endl;
    }
    return 0;
}
