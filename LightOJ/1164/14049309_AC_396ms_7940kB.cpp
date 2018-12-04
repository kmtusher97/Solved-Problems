#include<bits/stdc++.h>
#define long long long
using namespace std;

long tree[4*100000+7],lazy[4*100000+7],l,r,v;
void propagate(long node,long b,long e)
{
    if( !lazy[node] ) return;
    tree[node]+=(e-b+1)*lazy[node];
    if( b!=e ) {
    lazy[2*node]+=lazy[node];
    lazy[2*node+1]+=lazy[node];
    }
    lazy[node]=0;
}
///////////////////}
void update(long node,long b,long e)
{
    propagate(node,b,e);
    if(b>r||e<l)
        return;
    if(b>=l&&e<=r)
    {
        lazy[node]+=v;
        propagate(node,b,e);
        return;
    }
    long mid=(b+e)/2;
    update(2*node,b,mid);
    update(2*node+1,mid+1,e);
    tree[node]=tree[2*node]+tree[2*node+1];
}
long query(long node,long b,long e)
{
    propagate(node,b,e);
    if(b>r||e<l)
        return 0LL;
    if(b>=l&&e<=r)
    {
        //propagate(node,b,e);
        return tree[node];
    }
    long mid=(b+e)/2;
    long r1=query(2*node,b,mid);
    long r2=query(2*node+1,mid+1,e);
    return  r1+r2;
}
int main()
{
    long n,q,t=0,w,a,b,c;
    long test;
    scanf("%lld",&test);
    while(test--)
    {
        memset(tree,0,sizeof tree);
        memset(lazy,0,sizeof lazy);
        scanf("%lld %lld",&n,&q);
        printf("Case %lld:\n",++t);
        while(q--)
        {
            scanf("%lld %lld %lld",&w,&l,&r);
            if(w)
                printf("%lld\n",query(1,0,n-1));
            else
            {
                scanf("%lld",&v);
                update(1,0,n-1);
            }


        }
    }
}