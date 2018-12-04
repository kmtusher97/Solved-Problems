#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    int TC, length;
    cin >> TC;
    while(TC--) {
        cin >> length;
        int i, p[length];
        for(i=0; i<length; i++) {
            cin >> p[i];
        }
        int j, k, cnt = 0;
        for(j=0; j<i; j++) {
            for(k=j+1; k<i; k++) {
                if(p[j] > p[k]) cnt++;
            }
        }
        cout << "Optimal train swapping takes " << cnt << " swaps."<< endl;
    }

    return 0;
}

