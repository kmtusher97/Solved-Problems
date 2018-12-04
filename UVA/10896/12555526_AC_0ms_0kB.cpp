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
string ln, w;

int chk( string a, string b ) {
  int d = -1;
  for(int i=0; i<a.length(); i++) {
    int p = a[i]-96;
    int q = b[i]-96;
    if( p<q ) p+=26;
    if( i==0 ) {
      d = p-q;
    }
    else {
      if( p-q!=d ) return -1;
    }
  }
  return d;
}

int main() {
  ///read, write;
  FasterIO;
  int cases;
  cin>>cases;
  while( cases-- ) {
    cin.ignore();
    getline(cin, ln);
    cin>>w;
    stringstream ss(ln);
    string s;
    vector<char> vc;
    while( ss>>s ) {
      if( s.length()==w.length() ) {
        int d = chk(s, w);
        if( d!=-1 ) {
          vc.pb( (char)(d+'a') );
        }
      }
    }
    sort(vc.begin(), vc.end());
    for(int i=0; i<vc.size(); i++) {
      cout<<vc[i];
    }
    cout<<endl;
    ss.clear();
  }

  return 0;
}
