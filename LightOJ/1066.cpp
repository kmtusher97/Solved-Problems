#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define pbk pop_back
#define mk_pr make_pair

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<string> vss;
typedef queue<int> qi;

const int MX = 323456;
string grp[15];
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
bool vis[15][15];
int n, x, y, cst[15][15];

bool is_valid( int a, int b ) {
        if( a<0 || b<0 || a==n || b==n || vis[a][b] == true || grp[a][b]=='#' ) return false;
        return true;
}

int bfs( int lst ) {
        memset(vis, false, sizeof vis);
        memset(cst, 0, sizeof cst);
        qi q; q.push(x), q.push(y), cst[x][y] = 0, vis[x][y] = true;
        bool flg = false;

        while( !q.empty() ) {
                int u = q.front(); q.pop();
                int v = q.front(); q.pop();
                for(int i=0; i<4; i++) {
                        int uu = u+dx[i];
                        int vv = v+dy[i];
                        if( is_valid(uu, vv) ) {
                                if( grp[uu][vv] == '.' ) {
                                        vis[uu][vv] = true;
                                        q.push(uu), q.push(vv);
                                        cst[uu][vv] = cst[u][v]+1;
                                }
                                if( grp[uu][vv]-64 == lst+1 ) {
                                        vis[uu][vv] = true, x = uu, y = vv;
                                        q.push(uu), q.push(vv);
                                        cst[uu][vv] = cst[u][v]+1, flg = true;
                                        break;
                                }
                        }
                }
                if( flg ) break;
        }

        if( !flg ) return -1;
        return cst[x][y];
}


int main() {
        int cases, caseno=0;
        scanf("%d", &cases);
        while( cases-- ) {
                scanf("%d", &n);
                for(int i=0; i<n; i++) cin >> grp[i];

                int mx=0, x1, y1;
                for(int i=0; i<n; i++)
                for(int j=0; j<n; j++) {
                        if( grp[i][j] >= 'A' && grp[i][j] <= 'Z' ) {
                                if( mx < grp[i][j]-64 ) mx = grp[i][j]-64;
                                if( grp[i][j] == 'A' ) x1=i, y1=j;
                        }
                }

                int ans = 0;
                x = x1, y = y1;
                for(int i=1; i<mx; i++) {
                        grp[x][y] = '.';
                        int a = bfs(i);
                        if( a == -1 ) { ans = -1; break; }
                        ans += a;
                }

                printf("Case %d: ", ++caseno);
                if( ans == -1 ) printf("Impossible\n");
                else printf("%d\n", ans);
        }

        return 0;
}
