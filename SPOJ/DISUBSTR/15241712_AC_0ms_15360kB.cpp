/*  ~*BISMILLAHIR RAHMANIR RAHIM*~  */
#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
typedef long long intl;
#define MX_N 2010
char s[MX_N];

struct state {
  int len, link;
  map<char, int> next;
} st[MX_N];
int sz, last;
intl dp[MX_N];

void init() {
  sz = last = 0;
  for(int i = 0; i < MX_N; i++) {
    st[i].link=0;
    st[i].len=0;
    st[i].next.clear();
  }
  st[0].link = -1;
  memset(dp, 0, sizeof dp);
}

void Insert( char c ) {
  int cur = ++sz, p;
	st[cur].len = st[last].len + 1;
	for (p=last; p!=-1 && !st[p].next.count(c); p=st[p].link)
		st[p].next[c] = cur;
	if (p == -1)
		st[cur].link = 0;
	else {
		int q = st[p].next[c];
		if (st[p].len + 1 == st[q].len)
			st[cur].link = q;
		else {
			int clone = ++sz;
			st[clone].len = st[p].len + 1;
			st[clone].next = st[q].next;
			st[clone].link = st[q].link;
			for (; p!=-1 && st[p].next[c]==q; p=st[p].link)
				st[p].next[c] = clone;
			st[q].link = st[cur].link = clone;
		}
	}
	last = cur;
}

 intl dfs( int u ) {
    intl& ret = dp[u];
    if( ret ) return ret;

    ret = 1;
    for(auto it = st[u].next.begin(); it != st[u].next.end(); it++)
        ret += dfs( it->S );

    return dp[u] = ret;
}

int main() {
  int cases;
  scanf("%d", &cases);
  while( cases-- ) {
    scanf("%s", s);
    int n = strlen(s);
    init();
    for(int i = 0; i < n; i++)
      Insert( s[i] );

    printf("%lld\n", dfs( 0 ) - 1);
  }
  return 0;
}
