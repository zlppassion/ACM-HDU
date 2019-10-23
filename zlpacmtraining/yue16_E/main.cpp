#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int n;
int a[10][10];
//int vis[10][10];
set<int> ans;
void dfs(int x,int y,int num)
{
    if(x==n&&y==n)
    {
        ans.insert(num);
        return;
    }
    if(x>n||y>n||x<1||y<1)
        return;
    dfs(x+1,y,num+a[x+1][y]);
    dfs(x,y+1,num+a[x][y+1]);

}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }

    dfs(1,1,a[1][1]);
    cout<<ans.size()<<endl;
    return 0;
}
