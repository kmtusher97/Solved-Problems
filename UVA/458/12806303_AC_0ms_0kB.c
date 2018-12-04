#include <stdio.h>

int main()
{
    char line[200];
    while(gets(line)) {
        int ln = strlen(line);
        int i;
        for(i=0; i<ln; i++) {
            line[i] = line[i] - 7;
        }
        printf("%s\n", line);
    }

    return 0;
}