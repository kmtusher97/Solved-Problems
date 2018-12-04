#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    int r, c, cutr, cutc, cut;
    while(cin >> r >> c) {
        cutr = r-1;
        cutc = (c-1)*r;
        cut = cutr + cutc;
        cout << cut << endl;
    }

    return 0;
}

