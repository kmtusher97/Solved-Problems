/*11636 - Hello World!*/
#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

int main()
{
    double N, T = 1;
    while(cin >> N && N > 0)
    {
        int c = 0;
        double b = 2.0;
        if(N != 1) {
            while(b <= N*1.0) {
                b *= 2.0;
                c++;
            }
            if(pow(2, c) < N) c++;
        }
        cout << "Case " << T << ": " << c << endl;
        T++;
    }

    return 0;
}
