#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

#define MX 5008

int i, j, N;
long long cst, ar[MX];

main()
{
    while( scanf("%d", &N) == 1 && N )
    {
        for(i=0; i<N; i++)
        {
            scanf("%d", &ar[i]);
        }
        cst = 0, i = 1;
        while( i < N )
        {
            sort(ar, ar+N);
            //for(int j=0; j<N; j++) cout << " " << ar[j];
            //cout << endl << "cost" << endl;
            ar[i] = ( ar[i] + ar[i-1] );
            //cout << cst << endl;
            cst+=ar[i];
            i++;
        }

        printf("%lld\n", cst);
    }
}
