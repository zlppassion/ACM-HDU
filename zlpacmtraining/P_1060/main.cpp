#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int n,m;//��Ǯ��������
int v[30],p[30];//���ۣ���Ҫ��
int dp[30005];
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d",&v[i],&p[i]);
    }
   // dp[0]=0;
    for(int i=1;i<=m;i++)
    {
        for(int j=n;j>=v[i];j--)
        {
            dp[j]=max(dp[j],dp[j-v[i]]+v[i]*p[i]);
        }
    }
    cout<<dp[n]<<endl;
    return 0;
}
