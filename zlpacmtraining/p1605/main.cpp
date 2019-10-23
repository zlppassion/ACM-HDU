#include <iostream>
#include<bits/stdc++.h>
using namespace std;
const int maxn=30;
int n,m,T;
int kx[4]= {0,0,1,-1};
int ky[4]= {1,-1,0,0};
int vis[6][6];
struct node
{
    int x;
    int y;
} st,en,a[maxn];
int ans=0;
void dfs(int sx,int sy)
{
    if(sx==en.x&&sy==en.y)
    {
        ans++;
        return ;
    }

    for(int i=0; i<4; i++)
    {
        sx+=kx[i];
        sy+=ky[i];
        if(sx>n||sy>m||sx<1||sy<1||vis[sx][sy])
        {
            sx-=kx[i];
            sy-=ky[i];
            continue;
        }
        vis[sx][sy]=1;
        dfs(sx,sy);
        vis[sx][sy]=0;
         sx-=kx[i];
         sy-=ky[i];
    }
}

int main()
{
    scanf("%d%d%d",&n,&m,&T);
    scanf("%d%d%d%d",&st.x,&st.y,&en.x,&en.y);
    for(int i=0; i<T; i++)
    {
        scanf("%d%d",&a[i].x,&a[i].y);
        int t1=a[i].x,t2=a[i].y;
        vis[t1][t2]=1;
    }
    int xx=st.x,yy=st.y;
    vis[xx][yy]=1;
    dfs(st.x,st.y);
    cout<<ans<<endl;
    return 0;
}
