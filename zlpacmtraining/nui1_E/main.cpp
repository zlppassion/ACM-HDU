#include <iostream>
#include<bits/stdc++.h>
using namespace std;
//������һ���Ϸ�������Ϊ������n��AB��m��BA����ô��Ȼ��ǰn��A��ΪAB��A��ǰm��B��ΪBA��B��
//��Ϊ�����ǰn��A����һ����BA��A�������ǲ��ǿ��ԴӸ����������һ��A�����B�ã���ô��Ȼǰn��A��ΪAB��A
#define ll long long
const ll mod=1e9+7;
ll dp[2005][2005];//dp[i][j]����ǰ׺��i��A��j��B
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(int i=0;i<=n+m;i++)
        {
            for(int j=0;j<=n+m;j++)
                dp[i][j]=0;
        }
        dp[0][0]=1;
        for(int i=0;i<=n+m;i++)
        {
            for(int j=0;j<=n+m;j++)
            {
                if(i-j<n)//��Ϊǰn��ΪA ,�������A�ĸ�����û�д���B n������Ӧ�ü�A
                    dp[i+1][j]+=dp[i][j];
                if(j-i<m)//ͬ��
                    dp[i][j+1]+=dp[i][j];
                dp[i+1][j]%=mod;
                dp[i][j+1]%=mod;
            }
        }
        printf("%lld\n",dp[n+m][n+m]);
    }
    return 0;
}
