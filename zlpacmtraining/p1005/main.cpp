#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int a[85][85];
int vist[85],visw[85];//�ʼΪ0����������˾�Ϊ1;
ll dp[85][85][85];//��i�ε�j�е�k��
ll ans=0;
int n,m;
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
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {

            if(i==1)
            {
                vist[j]=1;
                visw[j]=m;
            }
            ll te=pow(2,i);
            if(te*a[j][vist[j]]<te*a[j][visw[j]])
            {
                ans+=te*a[j][vist[j]];
                vist[j]+=1;
            }
            else
            {
                 ans+=te*a[j][visw[j]];
                visw[j]-=1;
            }

        }
    }
    cout<<ans<<endl;
    return 0;
}
