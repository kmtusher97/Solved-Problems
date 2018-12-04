/*494 - Kindergarten Counting Game*/
#include <stdio.h>
#include <string.h>

int main()
{
    char line[10000];
    while(gets(line)) {
        int L = strlen(line);
        int i, word = 0, cont = 0;
        line[L] = ' ';
        for(i=0; i<=L; i++) {
            if((line[i] >= 'a' && line[i] <= 'z') || (line[i] >= 'A' && line[i] <= 'Z')) {
                cont++;
            }
            else {
                if(cont) word++;
                cont = 0;
            }
        }
        printf("%d\n", word);
    }

    return 0;
}
