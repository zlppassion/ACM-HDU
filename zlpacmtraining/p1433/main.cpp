#include <iostream>
#include<bits/stdc++.h>
using namespace std;
double ax[16],ay[16];
int n;
//priority_queue<double,vector<double>,greater<double> > ans;//从小到大
int vis[16];//判断这个点是否访问过
double as[16][16];
double ans=1231234424.0;//保证比每一条路径都要长
double dis(double x1,double y1,double x2,double y2)
{
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
void dfs(int step,int pos,double s)//pos代表当前编号，s代表距离总和
{
     if(s>ans)
        return;
      //if(!ans.empty()&&s>ans.top())
       // return;
    if(step==n)
    {
        //ans.push(s);
        ans=min(ans,s);
        return;
    }

    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            vis[i]=1;
            dfs(step+1,i,s+as[pos][i]);
            vis[i]=0;
        }
    }
}
int main()
{
    scanf("%d",&n);
    int te=0;
    for(int i=1;i<=n;i++)
    {
        cin>>ax[i]>>ay[i];

    }
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(i==j)
              as[i][j]=0;
            else
              as[i][j]=dis(ax[i],ay[i],ax[j],ay[j]);
        }
    }
    vis[0]=1;
    dfs(0,0,0);
  //  double f=ans.top();
    printf("%.2f\n",ans);
    return 0;
}
