#include<bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
#define ll long long
const int N=3005;
const int mod=998244353;
const double eps=1e-8;
const double PI = acos(-1.0);
#define lowbit(x) (x&(-x))
ll c[N][N],dp[N][N];
int main()
{
    std::ios::sync_with_stdio(false);
    int t;
    for(int i=0;i<N;i++)
    {
        c[i][0]=1;
        for(int j=1;j<=i;j++)
        {
            c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;
        }
    }
    scanf("%d",&t);
    while(t--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        char a[N],b[N];
        scanf("%s%s",a,b);
        ll ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=m+1;j<=n-i;j++)
            {
                if(a[i]!='0')
                {
                    ans=(ans+c[n-i-1][j-1])%mod;

                }
            }
        }
       // cout<<"GG"<<ans<<endl;
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=m;j++)
                dp[i][j]=0;
        }
        //dp[i][j]算的是长度相等的时候的答案
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                dp[i][j]=dp[i-1][j];
                if(a[n-i]>b[m-j])
                    dp[i][j]=(dp[i][j]+c[i-1][j-1])%mod;
                else if(a[n-i]==b[m-j])
                    dp[i][j]=(dp[i][j]+dp[i-1][j-1])%mod;
            }
        }
        for(int i=1;i<=n;i++)
        {

            for(int j=1;j<=m;j++)
                cout<<dp[i][j]<<" ";
            cout<<endl;
        }
        ans=(ans+dp[n][m])%mod;
        printf("%lld\n",ans);
    }
    return 0;
}/*
4 2
3821
50
*/
