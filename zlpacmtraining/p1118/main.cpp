#include<bits/stdc++.h>
using namespace std;
int a[13][13];
int vis[13];
int n,sum;
int g[13];
int flag=0;
void display()
{
    for(int i=1;i<=n;i++)
    {
        cout<<g[i]<<" ";
    }
    cout<<endl;
}
void dfs(int step,int ans)
{
    if(flag||ans>sum)
        return;//我没有剪枝，所以超时了。
    if(step==n+1&&ans==sum){
       display();
        flag=1;//标记
        return;
    }
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            g[step]=i;
            vis[i]=1;
            dfs(step+1,ans+i*a[n][step]);
            vis[i]=0;
        }
    }
}
int main()
{
    scanf("%d%d",&n,&sum);
    a[1][1]=1;
    for(int i=2;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            a[i][j]=a[i-1][j-1]+a[i-1][j];//杨辉三角递推式
        }
    }
    dfs(1,0);
    return 0;
}
