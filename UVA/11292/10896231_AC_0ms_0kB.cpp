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

const int MX = 112345;
int head[MX], knight[MX];

int main() {
  int n, m;
  while( scanf("%d %d", &n, &m) == 2 && n && m ) {
    for(int i=0; i<n; i++) {
      scanf("%d", head+i);
    }
    for(int i=0; i<m; i++) {
      scanf("%d", knight+i);
    }
    sort(head, head+n);
    sort(knight, knight+m);
    int cst = 0, h = 0;
    for(int i=0, lst=0; i<n; i++) {
      for(int j=lst; j<m; j++) {
        if( knight[j] >= head[i] ) {
          cst += knight[j];
          lst = j+1, h++;
          break;
        }
      }
    }
    if( h == n ) {
      printf("%d\n", cst);
    }
    else {
      printf("Loowater is doomed!\n");
    }
  }
  return 0;
}
