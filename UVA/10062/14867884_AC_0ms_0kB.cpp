/*  ~*BISMILLAHIR RAHMANIR RAHIM  */
#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second

typedef pair<int, int> pii;

int frq[500];
string s;

bool check( pii a, pii b ) {
  if( a.F != b.F ) return a.F < b.F;
  return a.S > b.S;
}

int main() {
  ios_base :: sync_with_stdio(false); cin.tie(NULL), cout.tie(NULL);
  int caseno = 0;
  while( getline(cin, s) ) {
    if( caseno++ ) cout << endl;
    memset(frq, 0, sizeof frq);
    for(int i = 0; s[i]; i++)
      frq[s[i]]++;

    vector<pii> v;
    for(int i = 0; i < 500; i++) {
      if( frq[i] ) v.push_back({frq[i], i});
    }

    int n = v.size();
    for(int i = 1; i < n; i++) {
      for(int j = i; j > 0; j--) {
        if( check( v[j], v[j - 1]) ) swap( v[j], v[j - 1] );
        else break;
      }
    }

    for(int i = 0; i < n; i++) {
      cout << v[i].S << " " << v[i].F << endl;
    }
  }
  return 0;
}
