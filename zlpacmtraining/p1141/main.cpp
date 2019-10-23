#include <bits/stdc++.h>
using namespace std;
const int MAXN=1010;
int  mapp[MAXN][MAXN];
bool vis[MAXN][MAXN];
int ans[MAXN][MAXN];
int sum[1000010];//此处需注意大小，以防止超出
int setp=0;
int n,m;
int dx[]= {1,-1,0,0};
int dy[]= {0,0,1,-1};
void dfs(int i,int j,int k)
{
    setp++;
    ans[i][j]=k;
    vis[i][j] = true;
    for (int l = 0; l <4 ; ++l)
    {
        int kx = i + dx[l];
        int ky = j + dy[l];
        if (kx >= 0 && kx < n && ky >= 0 && ky < n && mapp[kx][ky] ^ mapp[i][j] && !vis[kx][ky])
        {
            dfs(kx, ky, k);
        }
    }
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
        {
            scanf("%1d",&mapp[i][j]);
        }
    memset(vis,false,sizeof(vis));
    int k=0;
    for (int i=0; i<n; i++)
    {
        for (int j = 0; j <n ; ++j)
        {
            if(!vis[i][j])
            {
                dfs(i,j,k);
                sum[k]=setp;//第k个连通块的步数
                k++;
                setp=0;
            }
        }
    }
    int x,y;
    for (int j = 0; j <m ; ++j)
    {
        scanf("%d%d",&x,&y);
        printf("%d\n",sum[ans[x-1][y-1]]);
    }
    return 0;
}
