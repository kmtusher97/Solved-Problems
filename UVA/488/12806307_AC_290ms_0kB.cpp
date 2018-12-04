#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    int tc, f, am, i, j;
    cin >> tc;
    while(tc) {
        cin >> am >> f;
        while(f) {
            for(i=1; i<=am; i++) {
                for(j=1; j<=i; j++) { cout << i; }
                cout << endl;
            }
            for(i=am-1; i>=1; i--) {
                for(j=1; j<=i; j++) { cout << i; }
                cout << endl;
            }
            if(tc!=1 || f!=1) { cout << endl; }
            f--;
        }
        tc--;
    }

    return 0;
}

