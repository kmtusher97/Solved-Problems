/*136 - Ugly Numbers*/
#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int primeFcator(long long x)
{
    while(x % 2 == 0) {
        x /= 2;
    }

    for(int i=3; i<=sqrt(x); i+=2) {
        if(i > 5) return 0;
        while(x % i == 0) {
            x /= i;
        }
    }

    if(x > 5)
        return 0;
    else
        return 1;
}

int main()
{
    long long N=1, i=0;

    while(true) {
        if(!primeFcator(N)) N++;
        else {
            i++;
            if(i==1500) {
                cout << "The 1500'th ugly number is " << N << endl;
                break;
            }
            N++;
        }
    }

    return 0;
}

/*
#include <iostream>
using namespace std;

int main()
{
    cout << "The 1500'th ugly number is 859963392." << endl;

    return 0;
}
*/
