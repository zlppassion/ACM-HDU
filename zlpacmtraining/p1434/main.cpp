#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int a[105][105];
int vis[105][105];
int n,m;
int ans[10005];
int X[4]= {0,0,1,-1};
int Y[4]= {1,-1,0,0};
int tot=0;
void dfs(int x,int y,int cnt)
{

    if(cnt>n*m)
    {

        return;
    }

    int flag=0;
    for(int i=0; i<4; i++)
    {
        int nx=x+X[i];
        int ny=y+Y[i];
        if(nx>n||ny>m||nx<1||ny<1)//超出范围的路径
        {
            flag++;
            continue;
        }
        if(vis[nx][ny])
        {
            flag++;//已经访问过的点不能继续访问
            continue;
        }

        if(a[nx][ny]>=a[x][y])
        {
            flag++;//高度没有小于
            continue;
        }
    }
    if(flag>=4)//已经无处可走了
    {
        ans[tot++]=cnt;
        return;
    }
    for(int i=0; i<4; i++)
    {
        int newx=x+X[i];
        int newy=y+Y[i];
        if(newx>n||newy>m||newx<1||newy<1)
            continue;
        if(a[newx][newy]>=a[x][y])
            continue;
        if(vis[newx][newy])
            continue;
        vis[newx][newy]=1;
        dfs(newx,newy,cnt+1);
        vis[newx][newy]=0;
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    int maxa=-1;
    int posx,posy;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            scanf("%d",&a[i][j]);
            if(maxa<a[i][j])
            {
                maxa=a[i][j];

            }
        }
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(a[i][j]==maxa)
            {
                vis[i][j]=1;
                dfs(i,j,1);
                vis[i][j]=0;
            }
        }
    }
    sort(ans,ans+tot);
    cout<<ans[tot-1]<<endl;
    return 0;
}
