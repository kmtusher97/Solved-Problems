#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    char s[100000], t[100000];
    while(cin >> s) {
        cin >> t;
        int ln1, ln2;
        ln1=strlen(s), ln2=strlen(t);
        int i, j, n=0, m, cont=0;

        for(i=0; i<ln1; i++) {
            for(j=n; j<ln2; j++) {
                if(s[i]==t[j]) {
                    cont++;
                    m=j;
                    break;
                }
            }
            n=m+1;
        }
        if(cont==ln1) cout << "Yes" << endl;
        else cout << "No" << endl;
    }

    return 0;
}

