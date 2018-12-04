/**    ~* BISMILLAHIR RAHMANIR RAHIM *~    **/

#include <bits/stdc++.h>

using namespace std;

const int MX = 1123456;
int n, Q, seg_sz, a[MX], cnt[MX], ans[MX];

struct _node
{
  int lft, rgt, seg_no, id;

  _node() : lft(0), rgt(0), seg_no(0) { }

  bool operator < ( _node p ) const
  {
    if( seg_no!=p.seg_no ) return seg_no<p.seg_no;
    if( rgt!=p.rgt ) return rgt<p.rgt;
    return lft<p.lft;
  }
} qq[MX];

void addition( int st, int ed, int ii )
{
  for(int i=st; i<=ed; i++)
  {
    cnt[a[i]]++;
    if( cnt[a[i]]==1 ) ans[ii]++;
  }
}

void subtraction( int st, int ed, int ii )
{
  for(int i=st; i<=ed; i++)
  {
    cnt[a[i]]--;
    if( cnt[a[i]]==0 ) ans[ii]--;
  }
}

void solution()
{
  int pre_l, pre_r, cur_l, cur_r;
  for(int i=0; i<Q; i++)
  {
    cur_l = qq[i].lft, cur_r = qq[i].rgt;
    if( i==0 ) addition( cur_l, cur_r, qq[i].id );
    else
    {
      ans[qq[i].id] = ans[qq[i-1].id];
      if( cur_l>pre_l ) subtraction( pre_l, cur_l-1, qq[i].id );
      else addition( cur_l, pre_l-1, qq[i].id );

      if( cur_r>pre_r ) addition( pre_r+1, cur_r, qq[i].id );
      else subtraction( cur_r+1, pre_r, qq[i].id );
    }
    pre_l = cur_l, pre_r = cur_r;
  }
}

int main()
{
  //ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  //cin>>n;
  scanf("%d", &n);
  seg_sz = max(1, (int)sqrt(n));
  for(int i=1; i<=n; i++)
  {
    //cin>>a[i];
    scanf("%d", a+i);
  }
  //cin>>Q;
  scanf("%d", &Q);
  for(int i=0; i<Q; i++)
  {
    //cin>>qq[i].lft>>qq[i].rgt;
    scanf("%d %d", &qq[i].lft, &qq[i].rgt);
    qq[i].seg_no = qq[i].lft/seg_sz + ( (qq[i].lft%seg_sz>0) ? 1 : 0 );
    qq[i].id = i;
  }
  sort( qq, qq+Q );
  solution();
  for(int i=0; i<Q; i++)
  {
    //cout<<ans[i]<<endl;
    printf("%d\n", ans[i]);
  }
  return 0;
}
