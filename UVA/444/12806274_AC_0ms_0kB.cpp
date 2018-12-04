/*444 - Encoder and Decoder*/
#include <stdio.h>
#include <string.h>

void inttoString(int x)
{
    char num;
    int i = 0;
    while(x) {
        num = (x % 10) + 48;
        x /= 10;
        printf("%c", num);
    }

}

int check(int chVlu)
{
    if((chVlu >= 97 && chVlu <= 122) ||
       (chVlu >= 65 && chVlu <= 90) ||
       chVlu == 32 || chVlu == 33 ||
       chVlu == 44 || chVlu == 46 ||
       chVlu == 58 || chVlu == 59 || chVlu == 63) return 1;
    else return 0;
}

int main()
{
    char massage[1000];
    while(gets(massage)) {
        int L = strlen(massage);
        int i, j = 0, k;
        for(i=0; i<L; i++)
            if(massage[i] >= '0' && massage[i] <= '9') j++;

        if(j == i)
            for(k=L-1; k>=0; ) {
                int charVlu = 0;
                charVlu = (((massage[k] - 48) * 10) + (massage[k-1] - 48));
                if(check(charVlu) == 1) {
                    printf("%c", charVlu);
                    k-=2;
                }
                else {
                    charVlu = (((massage[k] - 48) * 100) + (massage[k-1] - 48) * 10 + (massage[k-2] - 48));
                    printf("%c", charVlu);
                    k-=3;
                }
            }
        else
            for(k=L-1; k>=0; k--) {
                int charVlu = massage[k];
                inttoString(charVlu);
            }

        printf("\n");
    }
    return 0;
}
