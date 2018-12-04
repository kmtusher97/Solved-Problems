#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define pbk pop_back
#define mk_pr make_pair

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef vector<string> vss;
typedef queue<int> qi;

const int MX = 21123456;
int dx[10] = {-1, 0, 1, 0, -1, -1, 1, 1};
int dy[10] = {0, 1, 0, -1, -1, 1, 1, -1};
string s[100];

bool valid( int x, int y, int n, int m ) {
  if( x < 0 || y < 0 || x >= n || y >= m ) return false;
  return true;
}

int main() {
  int cases, caseno = 0;
  scanf("%d", &cases);
  while( cases-- ) {
    int n, m, cnt1 = 0;
    scanf("%d %d", &n, &m);
    for(int i=0; i<n; i++) {
      cin >> s[i];
    }
    bool flg = true;
    for(int i=0; i<n; i++) {
      bool loop = false;
      for(int j=0; j<m; j++) {
        if( s[i][j] != 'F' ) {
          int cnt = 0;
          for(int k=0; k<8; k++) {
            if( valid( i+dx[k], j+dy[k], n, m ) && s[i+dx[k]][j+dy[k]] == 'F' ) {
              cnt++;
            }
          }
          if( cnt != s[i][j]-'0' ) {
            flg = false;
          }
        }
        else {
          cnt1++;
        }
      }
    }
    if( flg && cnt1 == n*m ) flg = false;
    flg ? printf("Well done Clark!") : printf("Please sweep the mine again!");
    printf("\n");
  }
  return 0;
}
