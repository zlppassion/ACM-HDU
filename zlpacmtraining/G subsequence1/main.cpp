#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 3e3+10;
const ll mod = 998244353;
ll dp[N][N],ans,C[N][N];
char s[N],t[N];
int n,m;
//dp[i][j]:从s串的前i个为数里选出j位数(长度为j的子序列)
//与t的前j位数相等的子序列数
int main(void)
{
    int T;
    scanf("%d",&T);
    C[0][0]=1;
    for(int i=1;i<=N-10;i++)
    {
        C[i][0]=1;
        for(int j=1;j<=i;j++)
            C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
    }
    while(T--)
    {
        scanf("%d%d%s%s",&n,&m,s+1,t+1);
        ans=0;

        //选出子序列长度等于t的长度，要保证前面某几位相同
        //中间至少一位大于t

        //初始化，选出0位数的子序列数肯定为1
        //即一个也不选
        for(int i=0;i<=n;i++)
            dp[i][0]=1;

        for(int i=1;i<=n;i++)
            for(int j=1;j<=min(i,m);j++)
            {
                //首先不管s[i]与t[j]有怎样的大小关系，总会有dp[i-1][j]个子序列满足条件
                //也就是不选s串中的第i位数
                dp[i][j]=dp[i-1][j];
                //只有s[i]==t[j]时，才能选s[i]，那要保证从s串的前i-1为中
                //选出来的j-1位数要相等
                if(s[i]==t[j]) dp[i][j]=(dp[i][j]+dp[i-1][j-1])%mod;
                //既然从s串中选出的子序列组成的数第j位已经大于t的第j位了，
                //那么后面无论怎么选都大于t表示的数
                if(s[i]>t[j])
                    ans=(ans+dp[i-1][j-1]*C[n-i][m-j]%mod)%mod;
            }
        //选出子序列的长度大于t的长度的情况
        //直接用组合数学公式算
        for(int i=1;i<=n;i++)
        {
            if(s[i]=='0') continue;
            for(int j=m;j<=n-i;j++)//i位充当第一个数字，所以在后n-i位中再选j位
                ans=(ans+C[n-i][j])%mod;
        }
        printf("%lld\n",ans);

    }

    return 0;
}
