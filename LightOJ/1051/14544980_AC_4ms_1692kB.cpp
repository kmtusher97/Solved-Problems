/*  ~*BISMILLAHIR RAHMANIR RAHIM*~  */
#include <bits/stdc++.h>
using namespace std;

#define MX_N 52
int n, ff[MX_N][4][6];
char s[MX_N];

bool Vowel( char c ) {
  return ( c=='A' || c=='E' || c=='I' || c=='O'|| c=='U' );
}

int dfs( int pos, int vwl, int cnsnt ) {
  if( vwl>=3 || cnsnt>=5 ) return 0;
  if( pos==n ) {
    return ( vwl<3 && cnsnt<5 );
  }
  int ret = ff[pos][vwl][cnsnt];
  if( ~ret ) return ret;

  ret = 1;
  if( s[pos]=='?' ) {
    for(int i='A'; i<='Z'; i++) {
      if( Vowel( i ) ) {
        if( !cnsnt ) ret &= dfs( pos+1, vwl+1, 0 );
        else ret &= dfs( pos+1, 1, 0 );
      }
      else {
        if( !vwl ) ret &= dfs( pos+1, 0, cnsnt+1 );
        else ret &= dfs( pos+1, 0, 1 );
      }
    }
  }
  else {
    if( Vowel( s[pos] ) ) {
      if( !cnsnt ) ret &= dfs( pos+1, vwl+1, 0 );
      else ret &= dfs( pos+1, 1, 0 );
    }
    else {
      if( !vwl ) ret &= dfs( pos+1, 0, cnsnt+1 );
      else ret &= dfs( pos+1, 0, 1 );
    }
  }
  return ff[pos][vwl][cnsnt] = ret;
}

int dfs1( int pos, int vwl, int cnsnt ) {
  if( vwl>=3 || cnsnt>=5 ) return 0;
  if( pos==n ) return ( vwl<3 && cnsnt<5 );
  int ret1 = ff[pos][vwl][cnsnt];
  if( ~ret1 ) return ret1;

  ret1 = 0;
  if( s[pos]=='?' ) {
    for(int i='A'; i<='Z'; i++) {
      if( Vowel( i ) ) {
        if( !cnsnt ) ret1 |= dfs1( pos+1, vwl+1, 0 );
        else ret1 |= dfs1( pos+1, 1, 0 );
      }
      else {
        if( !vwl ) ret1 |= dfs1( pos+1, 0, cnsnt+1 );
        else ret1 |= dfs1( pos+1, 0, 1 );
      }
    }
  }
  else {
    if( Vowel( s[pos] ) ) {
      if( !cnsnt ) ret1 |= dfs1( pos+1, vwl+1, 0 );
      else ret1 |= dfs1( pos+1, 1, 0 );
    }
    else {
      if( !vwl ) ret1 |= dfs1( pos+1, 0, cnsnt+1 );
      else ret1 |= dfs1( pos+1, 0, 1 );
    }
  }

  return ff[pos][vwl][cnsnt] = ret1;
}

int main() {
  int cases, caseno = 0;
  scanf("%d", &cases);
  while( cases-- ) {
    scanf("%s", s);
    n = strlen(s);
    memset(ff, -1, sizeof ff);
    int bad = dfs( 0, 0, 0 );
    memset(ff, -1, sizeof ff);
    int good = dfs1( 0, 0, 0 );
    printf("Case %d: ", ++caseno);
    if( good && !bad ) printf("MIXED\n");
    else if( good ) printf("GOOD\n");
    else printf("BAD\n");
  }
  return 0;
}

