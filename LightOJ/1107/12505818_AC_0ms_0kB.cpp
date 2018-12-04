/**    ~* BISMILLAHIR RAHMANIR RAHIM *~    **/
#include <bits/stdc++.h>

using namespace std;

#define sc scanf
#define pf printf
#define pb push_back
#define pbk pop_back
#define mk_pr make_pair

typedef long long intl;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<string> vss;
typedef queue<int> qi;
typedef queue<pii> qii;

#define read freopen("INPUT.txt", "r", stdin)
#define write freopen("OUTPUT.txt", "w", stdout)
#define FasterIO ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

const int MX = 112;

int main() {
  ///read, write;
  int T, TC=0;
    scanf("%d", &T);

    while(T--) {
        int x1, y1, x2, y2, x, y, N;
        scanf("%d%d%d%d%d", &x1, &y1, &x2, &y2, &N);

        printf("Case %d:\n", ++TC);
        while(N--) {
            scanf("%d%d", &x, &y);
            if((x>=x1 && x<=x2) && (y>=y1 && y<=y2)) printf("Yes\n");
            else printf("No\n");
        }
    }

  return 0;
}
