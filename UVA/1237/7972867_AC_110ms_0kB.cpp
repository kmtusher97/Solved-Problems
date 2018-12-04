#include <iostream>
#include <sstream>
#include <cstdio>
#include <utility>
#include <algorithm>
#include <cstring>

using namespace std;

typedef pair<int, int> pii;
typedef pair<pii, string> piiss;

#define MX 10005

pii mypair[MX];
piiss mypair1[MX];

main()
{
    int cases, caseno = 0, i, j, n, a, b;
    string line;
    scanf("%d", &cases);
    while( cases-- )
    {
        scanf("%d", &n);
        getchar();
        i = 0;
        while( n-- )
        {
            getline(cin, line);
            stringstream ss(line);
            ss >> mypair1[i].second >> mypair[i].first >> mypair[i].second;
            mypair1[i].first = mypair[i];
            i++;
        }
        /*for(j=0; j<i; j++) {
            cout << mypair[j].first << " " << mypair[j].second << " " << mypair1[j].second << endl;
        }*/
        scanf("%d", &a);
        while( a-- )
        {
            scanf("%d", &b);
            int chk = 0;
            for(j=0; j<i; j++)
            {
                if( b >= mypair[j].first && b <= mypair[j].second )
                {
                    line = mypair1[j].second;
                    chk++;
                }
            }
            if( chk == 1 ) cout << line << endl;
            else printf("UNDETERMINED\n");
        }
        if( cases ) printf("\n");
    }
}
