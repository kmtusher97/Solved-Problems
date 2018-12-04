/*575 - Skew Binary*/
#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    char sqbin[500];
    while(cin >> sqbin) {
        if(strlen(sqbin)==1 && sqbin[0]=='0') break;
        int sum=0, mult=2;
        for(int i=strlen(sqbin)-1; i>=0; i--) {
            int d = (sqbin[i]-48) * (mult-1);
            sum += d;
            mult *= 2;
        }
        cout << sum << endl;
    }

    return 0;
}

