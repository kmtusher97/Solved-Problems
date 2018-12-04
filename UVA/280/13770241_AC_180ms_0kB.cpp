#include<bits/stdc++.h>

using namespace std;

vector<int>graph[110];
int color[110], color1[110];

void resetColor(int m)
{
    for(int i=0; i<=m; i++)
    {
        color[i]=color1[i]=0;
    }
}

void init(int m)
{
    resetColor(m);
    for(int i=0; i<=m; i++)
    {
        graph[i].clear();
    }
}

bool isValidMove(int n)
{
    if(color[n]==0)
        return true;
    return false;
}

int dfs(int u)
{
    color[u]=1;

    int v;
    int res=1;
    for(int i=0; i<graph[u].size(); i++)
    {
        v=graph[u][i];
        color1[v]=1;
        if(isValidMove(v))
        {
            res+=dfs(v);
        }
    }
    color[u]=2;

    return res;
}
int main()
{
    int n,u,v,q;
    while(cin>>n)
    {
        if(n==0)
            break;

        init(n);

        while(cin>>u)
        {
            if(u==0)
                break;
            while(cin>>v)
            {
                if(v==0)
                    break;
                graph[u].push_back(v);
            }
        }

        cin>>q;
        while(q--)
        {
            cin>>u;
            resetColor(n);
            dfs(u);

            vector<int> inrc;
            for(int ii=1; ii<=n; ii++)
            {
                if( !color1[ii] )
                {
                    inrc.push_back(ii);
                }
            }

            if( inrc.empty() )
            {
                cout<<0<<endl;
            }
            else
            {
                cout<<inrc.size();
                for(int it : inrc)
                {
                    cout<<" "<<it;
                }
                cout<<endl;
            }
        }
    }
}
/*

*/
