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

const int MX = 41234;
int x, y, k, row[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
bool vis[10];

bool valid_permutation( int *tmp ) {
  bool board[9][9];
  memset(board, false, sizeof board);
  for(int i=1; i<=8; i++) {
    board[tmp[i]][i] = true;
  }
  for(int i=1, cnt, r, c; i<=8; i++) {
    cnt = 0;
    for(int j=1; j<=8; j++) { /// horizontal
      if( board[i][j] ) {
        r = i, c = j, cnt++;
      }
      if( cnt > 1 ) return false;
    }
    cnt = 0;
    int r1 = r, c1 = c;
    while( r1>0 && c1>0 ) { /// top left
      if( board[r1][c1] ) cnt++;
      if( cnt > 1 ) return false;
      r1--, c1--;
    }
    cnt = 0, r1 = r, c1 = c;
    while( r1<=8 && c1>0 ) { /// bottom left
      if( board[r1][c1] ) cnt++;
      if( cnt > 1 ) return false;
      r1++, c1--;
    }
    cnt = 0, r1 = r, c1 = c;
    while( r1<=8 && c1<=8 ) { /// bottom right
      if( board[r1][c1] ) cnt++;
      if( cnt > 1 ) return false;
      r1++, c1++;
    }
    cnt = 0, r1 = r, c1 = c;
    while( r1>0 && c1<=8 ) { /// top right
      if( board[r1][c1] ) cnt++;
      if( cnt > 1 ) return false;
      r1--, c1++;
    }
  }
  return true;
}

void backtrack( int pos, int *tmp ) {
  if( pos == 9 ) {
    if( tmp[y] == x && valid_permutation( tmp ) ) {
      printf("%2d      %d", ++k, tmp[1]);
      for(int i=2; i<=8; i++) {
        printf(" %d", tmp[i]);
      }
      printf("\n");
    }
    return;
  }
  for(int i=1; i<=8; i++) {
    if( !vis[i] ) {
      vis[i] = true, tmp[pos] = row[i];
      backtrack( pos+1, tmp );
      vis[i] = false;
    }
  }
}

int main() {
  int cases, t[10];
  scanf("%d", &cases);
  while( cases-- ) {
    scanf("%d %d", &x, &y);
    printf("SOLN       COLUMN\n #      1 2 3 4 5 6 7 8\n\n");
    memset(vis, false, sizeof vis), k = 0;
    backtrack( 1, t );
    if( cases ) printf("\n");
  }
  return 0;
}
