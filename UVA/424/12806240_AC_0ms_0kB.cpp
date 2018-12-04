#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;
char sum[1000], number1[1000], number2[1000];

int main()
{
    while(scanf("%s", number2) == 1) {
        if(!strcmp(number2, "0")) {
            for(int i=strlen(sum)-1; i>=0; i--)
                printf("%c", sum[i]);
            printf("\n");
            break;
        }

        if(number2 != "0") {

            int i, j, L = 0, Ln = 0, carry = 0;
            int L1 = strlen(number1), L2 = strlen(number2);

            for(i=L1-1, j=L2-1; ; i--, j--) {
                int a, b, s;
                    a = number1[i] - 48;
                    b = number2[j] - 48;

                if(i < 0) a = 0;
                if(j < 0) b = 0;

                if(i < 0 && j < 0) {
                    if(carry > 0) sum[L++] = carry + 48;
                    break;
                }

                    s = carry + a + b;
                    carry = s / 10;
                    sum[L++] = (s%10) + 48;
            }
            for(i=L-1; i>=0; i--)
                number1[Ln++] = sum[i];

            number1[Ln] = '\0';
        }
    }

    return 0;
}
