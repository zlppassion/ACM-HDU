#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int q[65];//���������ı��
int n,m;
int v[65],p[65];//�۸����Ҫ��
int vis[65];//�ж�i����Ʒ�Ƿ���
int dp[32005];
int main()
{
    scanf("%d%d",&n,&m);//��Ǯ������Ʒ����
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
