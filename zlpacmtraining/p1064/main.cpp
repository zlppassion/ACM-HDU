#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int q[65];//所属主件的编号
int n,m;
int v[65],p[65];//价格和重要度
int vis[65];//判断i号物品是否购买
int dp[32005];
int main()
{
    scanf("%d%d",&n,&m);//总钱数，物品个数
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d%d",&v[i],&p[i],&q[i]);
    }
     for(int i=1;i<=m;i++)
    {
        for(int j=n;j>=v[i];j--)
        {
            dp[j]=max(dp[j],dp[j-v[i]]+v[i]*p[i]);
        }
    }
    return 0;
}
