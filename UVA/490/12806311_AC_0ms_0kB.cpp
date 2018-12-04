/*490 - Rotating Sentences*/
#include <bits/stdc++.h>
using namespace std;
char senteces[110][110];

int main()
{
    int i, r=0, j, mxlen=0;

    for(i=0; i<110; i++)
        for(j=0; j<110; j++)
            senteces[i][j] = ' ';

    while(gets(senteces[r])) {
        int  l=strlen(senteces[r]);
        if(!l) break;
        if(l>mxlen) mxlen=l;
        r++;
    }

    for(j=0; j<mxlen; j++) {
        for(i=r-1; i>=0; i--) {
            if(senteces[i][j] == '\0') printf(" ");
            else
                printf("%c", senteces[i][j]);
        }
        printf("\n");
    }

    return 0;
}
