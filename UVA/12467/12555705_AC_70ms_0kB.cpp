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

const int MX = 1123456;
string w;
bool vis[MX];
vi p;

int main() {
  ///read, write;
  FasterIO;
  int cases;
  cin>>cases;
  while( cases-- ) {
    cin>>w;
    int ln = w.length();
    p.clear();

    bool flg = true;
    for(int i=0; i<ln; i++) {
      if( w[i]==w[0] ) {
        p.pb(i);
      }
      if( i>0 && w[i]!=w[i-1] ) flg = false;
    }

    if( flg ) {
      cout<<w<<endl;
      continue;
    }

    //memset(vis, 0, sizeof vis);
    string lst = "", cur = "";

    while( p.size()>0 ) {
      int st = p.back(); p.pbk();

      if( lst.length()>=st+1 ) break;
      //if( vis[st] ) continue;

      for(int i=st, j=0; i>=0 && j<ln; i--, j++) {
        //vis[i] = true;
        if( w[j]==w[i] ) {
          cur += w[i];
        }
        else break;
      }

      if( cur.length()>lst.length() ) {
        lst = cur;
      }
      cur = "";
    }

    for(int i=lst.length()-1; i>=0; i--) {
      cout<<lst[i];
    }
    cout<<endl;
  }

  return 0;
}
