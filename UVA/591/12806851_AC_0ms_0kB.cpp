#include <iostream>
using namespace std;

int main()
{
    int n, h, t=1, avg;
    while(cin >> n) {
        if(n == 0) break;
        int arr[n], i, j, sum, cnt, m;
        for(i=0, sum=0; i<n; i++) { cin >> arr[i]; sum += arr[i]; }
        if(sum % n == 0) {
            avg = sum / n;
            for(j=0, cnt=0; j<i; j++) {
                if(arr[j] > avg) { m = arr[j] - avg; cnt += m; }
            }
            cout << "Set #" << t << endl << "The minimum number of moves is " << cnt << "." << endl;
            cout << endl;
        }
        t++;
    }

    return 0;
}

