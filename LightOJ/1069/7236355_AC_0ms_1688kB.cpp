/*
*************************
      _dark_knight
*************************
    Light OJ problem 1069
*/
#include <bits/stdc++.h>
using namespace std;

/*
    * it takes 4 seconds for the lift to go from any floor to its adjacent floor
    * It takes 3 seconds to open or close the door
    * you need 5 seconds to enter or exit the lift
*/
int main()
{
    int T, TC=0;
    scanf("%d", &T);

    while(T--) {
        int my_pos, lift_pos, time;
        scanf("%d%d", &my_pos, &lift_pos);
        // required time
        time=19+(abs(my_pos-lift_pos)*4)+(my_pos*4);

        printf("Case %d: %d\n", ++TC, time);
    }

    return 0;
}
