#include <bits/stdc++.h>
using namespace std;

main()
{
    int n, i;
    while( cin >> n && n )
    {
        priority_queue<int> PQ;
        for(i=0; i<n; i++)
        {
            int a;
            cin >> a;
            PQ.push( -1*a );
        }

        int sm = 0, cnt = 0;

        while( !PQ.empty() )
        {
            int a = 0, b = 0;
            a = PQ.top(), PQ.pop();
            cnt = a;
            if( !PQ.empty() )
            {
                b =PQ.top(), PQ.pop();
            }
            else break;
            cnt += b;
            sm += cnt;
            PQ.push( cnt );
        }

        cout << sm*-1 << endl;
    }
}
