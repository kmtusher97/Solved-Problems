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

const int MX = 1123456;
int a[MX];

int main() {
  int n;
  while( scanf("%d", &n) == 1 ) {
    for(int i=0; i<n; i++) {
      char ch;
      scanf("%d%c", a+i, &ch);
    }
    for(int i=0; i<n; i++) {
      if( a[i]==2 || a[i]==3 || a[i]==5 || a[i]==7 || a[i]==13 || a[i] == 17 ) {
        printf("Yes\n");
      }
      else {
        printf("No\n");
      }
    }
  }
  return 0;
}
