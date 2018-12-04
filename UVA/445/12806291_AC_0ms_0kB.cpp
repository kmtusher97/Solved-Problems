/*445 - Marvelous Mazes*/
#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;
char line [100000];

int main()
{
    while(gets(line)) {
        int i, j, d = 0, a;

        for(i=0; i<strlen(line); i++) {
            if(line[i] >= '0' && line[i] <= '9') {
                a = line[i] - 48;
                if(line[i-1] >= '0' && line[i-1] <= '9') d += a;
                else d = a;
            }
            else if((line[i] >= 'A' && line[i] <= 'Z') || line[i] == '*') {
                for(j=1; j<=d; j++)
                    printf("%c", line[i]);

                d = 0;
            }
            else if(line[i] == 'b') {
                for(j=1; j<=d; j++)
                    printf(" ");

                d = 0;
            }
            else if(line[i] == '!') printf("\n");
        }

        printf("\n");

    }

    return 0;
}
