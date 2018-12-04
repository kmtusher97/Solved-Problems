#include <iostream>
using namespace std;

int main()
{
    int n, i, t, sum;
    while(cin >> n) {
        if(n==0) break;
        for(i=n, sum=0; i>=1; i--) {
            t = i*i; sum += t;
        }
        cout << sum << endl;
    }

    return 0;
}

