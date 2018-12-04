/*  ~*BISMILLAHIR RAHMANIR RAHIM*~  */
#include <bits/stdc++.h>
using namespace std;
typedef long long intl;

#define MX_N 1002
char s[MX_N];

struct state {
  int len, link, next[60];
} st[MX_N * 2];
int sz, last;
intl dp[MX_N * 2];

void init( )
{
  sz=0,last=0;
  for(int i=0;i<2*MX_N;i++)
  {
    st[i].link=0;
    st[i].len=0;
    memset(st[i].next,0,sizeof(st[i].next));
  }
  st[0].link=-1;
}
void Insert( int c ) {
  int now = ++sz, p;
  st[now].len = st[last].len + 1;

  for(p = last; ~p && !st[p].next[c]; p = st[p].link)
    st[p].next[c] = now;

  if( !(p + 1) )
    st[now].link = 0;
  else {
    int q = st[p].next[c];
    if( st[q].len == st[p].len + 1 )
      st[now].link = q;
    else {
      int clone = ++sz;
      st[clone].len = st[p].len + 1;
      st[clone].link = st[q].link;
      for(int j = 0; j < 60; j++)
        st[clone].next[j] = st[q].next[j];

      for(; ~p && st[p].next[c] == q; p = st[p].link)
        st[p].next[c] = clone;

      st[q].link = st[now].link = clone;
    }
  }
  last = now;
}

int main() {
  int cases;
  scanf("%d", &cases);
  while( cases-- ) {
    scanf("%s", s);
    int n = strlen(s);
    init();
    intl ans=0;
    for(int i = n-1; i>=0; i--)
    {
      Insert( s[i] - 'A' );
      ans=ans+n-i-st[st[last].link].len;
    }
    printf("%lld\n", ans);
  }
  return 0;
}
