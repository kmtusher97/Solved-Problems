/*499 - What's The Frequency, Kenneth*/
#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;
int charvlu[127];

int main()
{
    char line[1000];
    while(gets(line)) {
        int i;

        for(i=64; i<127; i++)
            charvlu[i] = 0;

        for(i=0; i<strlen(line); i++) {
            if((line[i] >= 'A' && line[i] <= 'Z') || (line[i] >= 'a' && line[i] <= 'z'))
                ++charvlu[line[i]];

        }

        int mx = charvlu[0];
        for(i=64; i<127; i++)
            if(charvlu[i] > mx)
                mx = charvlu[i];

        for(i=0; i<127; i++)
            if(mx == charvlu[i])
                printf("%c", i);

        printf(" %d\n", mx);

    }

    return 0;
}
