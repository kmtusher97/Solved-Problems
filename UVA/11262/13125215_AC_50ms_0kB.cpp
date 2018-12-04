/**  ~*BISMILLAHIR RAHMANIR RAHIM*~  **/

#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second

typedef long long intl;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int MX = 1002;
int r, b, n, K;
pii R[MX], B[MX];

struct Hopcroft_Karp
{
  int N, M, match[1000], dist[1000];
  vi G[500];

  Hopcroft_Karp( int _n, int _m )
  {
    N = _n, M = _m;
    memset(match, 0, sizeof match);
  }

  bool bfs()
  {
    queue<int> Q;
    for(int i=1; i<=N; i++)
    {
      if( match[i]==0 ) dist[i] = 0, Q.push(i);
      else dist[i] = INT_MAX;
    }
    dist[0] = INT_MAX;

    while( !Q.empty() )
    {
      int u = Q.front(); Q.pop();
      if( u==0 ) continue;
      for(int i=0; i<G[u].size(); i++)
      {
        int v = G[u][i];
        if( dist[match[v]]!=INT_MAX ) continue;
        dist[match[v]] = dist[u] + 1;
        Q.push(match[v]);

      }
    }
    return (dist[0]!=INT_MAX);
  }

  bool dfs( int u )
  {
    if( u!=0 )
    {
      for(int i=0; i<G[u].size(); i++)
      {
        int v = G[u][i];
        if( dist[match[v]]==dist[u]+1 )
        {
          if( dfs( match[v] ) )
          {
            match[u] = v;
            match[v] = u;
            return true;
          }
        }
      }
      dist[u] = INT_MAX;
      return false;
    }
    return true;
  }

  int Maximum_Bipartite_Matching()
  {
    int matching = 0;
    while( bfs() )
    {
      for(int i=1; i<=N; i++)
      {
        if( match[i]==0 && dfs( i ) ) matching++;
      }
    }
    return matching;
  }

};

double dist_eq( pii a, pii b )
{
  return sqrt((a.F-b.F)*(a.F-b.F) + (a.S-b.S)*(a.S-b.S));
}

void make_Graph( Hopcroft_Karp& st, double d )
{
  for(int i=1; i<=r; i++)
  {
    for(int j=1; j<=b; j++)
    {
      if( dist_eq( R[i], B[j] )<=d ) st.G[i].push_back(j+r);
    }
  }
}

int main()
{
  ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int cases;
  cin>>cases;
  while( cases-- )
  {
    cin>>n>>K;
    r = b = 0;
    for(int i=1, x, y; i<=n; i++)
    {
      string s;
      cin>>x>>y>>s;
      if( s=="blue" ) B[++b] = pii(x, y);
      else R[++r] = pii(x, y);
    }

    intl lo = 1, hi = 1e7, mid, ans = -1;
    while( lo<=hi )
    {
      mid = (lo+hi)/2;

      Hopcroft_Karp BPM( r, b );
      make_Graph( BPM, mid );
      int res = BPM.Maximum_Bipartite_Matching();

      if( res>=K ) hi = mid-1, ans = mid;
      else lo = mid+1;
    }

    if( ans==-1 ) cout<<"Impossible"<<endl;
    else cout<<lo<<endl;
  }
  return 0;
}
