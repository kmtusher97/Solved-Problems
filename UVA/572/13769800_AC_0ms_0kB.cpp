#include<bits/stdc++.h>

using namespace std;

int dx8[]= {0, 0, 1, 1, 1,-1,-1,-1};
int dy8[]= {1,-1,-1, 0, 1,-1, 0, 1};

char graph[110][110];
int color[110][110];

void init(int m,int n)
{
    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            color[i][j]=0;
        }
    }
}

bool isValidMove(int r,int c, int m,int n)
{
    if(r>=0&&r<m&&c>=0&&c<n && graph[r][c]=='@'&&color[r][c]==0) return true;
    return false;
}

void dfs(int r,int c,int m,int n)
{
    color[r][c]=1;
    for(int i=0; i<8; i++)
    {
        if(isValidMove(r+dx8[i],c+dy8[i],m,n))
        {
            dfs(r+dx8[i],c+dy8[i],m,n);
        }
    }
    color[r][c]=2;
}
int main()
{
    int m,n;
    while(scanf("%d%d",&m,&n)==2)
    {
        if(m==0)break;
        init(m,n);
        for(int i=0; i<m; i++)
        {
            cin>>graph[i];
        }

        int cnt = 0;
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(graph[i][j]=='@'&&color[i][j]==0)
                {
                    dfs(i,j,m,n);
                    cnt++;
                }
            }
        }
        cout<<cnt<<endl;
    }
}
/*

*/
