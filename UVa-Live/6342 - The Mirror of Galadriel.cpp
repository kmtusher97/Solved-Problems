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

const int MX = 1123456;
bool mark[MX];

int main() {
  int cases, n, m;
  scanf("%d", &cases);
  while( cases-- ) {
    char s[100];
    scanf("%s", s);
    bool flg = true;
    for(int i=0, ln=strlen(s); i<ln; i++) {
      if( s[i] != s[ln-i-1] ) {
        printf("NO\n");
        flg = false; break;
      }
    }

    if( !flg ) continue;
    printf("YES\n");
  }
  return 0;
}
