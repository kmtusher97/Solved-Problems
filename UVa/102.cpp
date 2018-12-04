/*
 UVA problem 102 - Ecological Bin Packing
 KAMRUL HASAN TUSHER
 JU CSE'25

*/

#include <bits/stdc++.h>
#define LL long long
using namespace std;
char order[6][4] = {"BCG", "BGC", "CBG", "CGB", "GBC", "GCB"};

int main()
{
    int bottol[10], pos, i, j;

    while(scanf("%d", &bottol[0])==1) {
        for(i=1; i<9; i++)
            scanf("%d", &bottol[i]);

        LL movement[9], MIN;

        movement[0] = bottol[3]+bottol[6]+bottol[2]+bottol[8]+bottol[1]+bottol[4];
        movement[1] = bottol[3]+bottol[6]+bottol[1]+bottol[7]+bottol[2]+bottol[5];
        movement[2] = bottol[5]+bottol[8]+bottol[0]+bottol[6]+bottol[1]+bottol[4];
        movement[3] = bottol[5]+bottol[8]+bottol[1]+bottol[7]+bottol[0]+bottol[3];
        movement[4] = bottol[4]+bottol[7]+bottol[0]+bottol[6]+bottol[2]+bottol[5];
        movement[5] = bottol[4]+bottol[7]+bottol[2]+bottol[8]+bottol[0]+bottol[3];

        MIN=movement[0], pos=0;

        for(i=1; i<6; i++)
            if(movement[i]<MIN) MIN=movement[i], pos=i;

        printf("%s %lld\n", order[pos], MIN);
    }

    return 0;
}
