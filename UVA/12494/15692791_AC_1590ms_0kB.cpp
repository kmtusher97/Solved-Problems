/* BISMILLAHIR RAHMANIR RAHIM */
#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int cases;
  cin >> cases;
  while( cases-- ) {
    string s;
    cin >> s;
    set<string>st;
    for(int i = 1, ln = s.length(); i <= ln; i++)
      for(int j = 0; j + i <= ln; j++) {
        string tmp = s.substr(j, i), mn = tmp;
        for(int k = 0, ln1 = tmp.length(); k < ln1; k++) {
          tmp = tmp.back() + tmp;
          tmp.pop_back();
          mn = min(mn, tmp);
        }
        st.emplace(mn);
      }

    cout << st.size() << endl;
  }
  return 0;
}
