#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int a[105][105];
int h[105][105];
int n,m;
int X[4]={0,0,1,-1};
int Y[4]={1,-1,0,0};
int dfs(int x,int y)
{
    if(h[x][y])
        return h[x][y];//该点的最长路已经计算过了，直接返回即可。
    //没有计算过，直接赋值为1，1个数长度为1
    h[x][y]=1;
    for(int i=0;i<4;i++)
    {
        int newx=x+X[i];
        int newy=y+Y[i];
        if(newx>n||newy>m||newx<1||newy<1)
           continue;
        if(a[newx][newy]<a[x][y])
        h[x][y]=max(h[x][y],1+dfs(newx,newy));
    }
    return h[x][y];


}
int ans=0;
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            scanf("%d",&a[i][j]);

        }

    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            ans=max(ans,dfs(i,j));

        }

    }
    cout<<ans<<endl;
    return 0;
}
