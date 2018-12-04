#include <bits/stdc++.h>
using namespace std;

int main()
{
    int tc, m;
    long long sum=0;
    string s;
    cin>>tc;
    while(tc--) {
        cin>>s;
        if(s!="report") {
            cin>>m;
            sum+=m;
        }
        else
            cout<<sum<<endl;
    }

    return 0;
}
