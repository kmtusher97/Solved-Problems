#include <bits/stdc++.h>
using namespace std;
string friends[2005], name;
int mny[2005];

int index(int n)
{
    for(int i=0; i<n; i++)
        if(name==friends[i]) return i;
}

int main()
{
    int N, i, mn, n, t=0;
    /* number of friends */
    while(cin >> N) {
        // names
        for(i=0; i<N; i++)
            cin >> friends[i];

        memset(mny, 0, sizeof(mny));

        int M=N, a;
        while(M--) {
            cin >> name >> mn >> n;
            if(n) a=mn/n, mn=a*n*(-1);
            else mn=0;
            mny[index(N)]+=mn;

            while(n--) {
                cin >> name;
                mny[index(N)]+=a;
            }
        }

        if(t++) cout << endl;

        for(i=0; i<N; i++)
            cout << friends[i] << " " << mny[i] << endl;
    }


    return 0;
}
