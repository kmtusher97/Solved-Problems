#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
    //freopen("file2.txt", "r", stdin);
    //freopen("file3.txt", "w", stdout);
    char S[100001], s1[1001];
    int tc;
    scanf("%d", &tc);

    while(tc--) {
        scanf("%s", S);
        int L=strlen(S), i, n;
        scanf("%d", &n);
        while(n--) {
            scanf("%s", s1);
            int j, l=strlen(s1);
            bool chk=false, flg=false;

            for(i=0; i<L; i++) {
                if(s1[0]==S[i]) {
                    for(j=0; j<l; j++) {
                        if(s1[j]==S[i++])
                            chk=true;
                        else {
                            chk=false;
                            break;
                        }
                    }
                }
                if(chk) {
                    flg=true;
                    break;
                }
            }

            if(flg) printf("y\n");
            else printf("n\n");
        }
    }

    return 0;
}
