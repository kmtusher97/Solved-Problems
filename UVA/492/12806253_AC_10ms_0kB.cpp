/*492 - Pig-Latin*/
#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;
char line[10000000];
int main()
{
    char ch;
    while(gets(line)) {
        int L = strlen(line);
        int i, j = 0;
        ch = '\0';

        for(i=0; i<=L; i++) {
            if((line[i] >= 'A' && line[i] <= 'Z') || (line[i] >= 'a' && line[i] <= 'z')) {
                j++;
                if(j == 1) {
                    if(line[i] == 'a' || line[i] == 'A' || line[i] == 'e' || line[i] == 'E' ||
                       line[i] == 'i' || line[i] == 'I' || line[i] == 'o' || line[i] == 'O' ||
                       line[i] == 'u' || line[i] == 'U') printf("%c", line[i]);
                    else ch = line[i];
                }
                else printf("%c", line[i]);
            }
            else {
                if(j) {
                    if(ch) printf("%cay", ch);
                    else printf("ay");
                }
                j = 0;
                ch = '\0';
                if(i != L) printf("%c", line[i]);
            }
        }

        printf("\n");
    }


    return 0;
}
