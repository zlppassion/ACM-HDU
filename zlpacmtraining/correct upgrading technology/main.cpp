#include<bits/stdc++.h>
#define maxn 1005
#define LL long long
using namespace std;
int T,n,m,x;
LL ans,sum,D,s[maxn][maxn],mx[maxn][maxn];
int main()
{
    //cout<<(-1ll<<60)<<endl;
    scanf("%d",&T);
    for(int _=1; _<=T; _++)
    {
        scanf("%d%d",&n,&m);
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=m; j++)
                scanf("%d",&x),s[i][j]=s[i][j-1]-x;//s[i][j]代表累计到这里的扣的钱
            mx[i][m+1]=-1ll<<60;//一个绝对值巨大的负数
            for(int j=m; j>=0; j--)
                mx[i][j]=max(mx[i][j+1],s[i][j]); //往前更新扣钱数目最少（这里越大说明扣钱数目越少）
        }

        ans=D=0;
        for(int j=0; j<=m; j++)
        {
            if(j) scanf("%d",&x),D+=x;//全部登上台阶的奖励值
            //sum=0;
            sum=-1ll<<60;
            for(int i=1; i<=n; i++)
                if(s[i][j]-mx[i][j]>sum)//mx[i][j]一定是大于等于s[i][j]的，所以这里sum最大就只可能为0，否则为负数
                    sum=s[i][j]-mx[i][j];
            for(int i=1; i<=n; i++)
                sum+=mx[i][j];
            ans=max(ans,sum+D);
        }
        /* for(int i=1;i<=n;i++)
        {
            for(int j=0;j<=m;j++)
            {
                cout<<s[i][j]<<" ";
            }
            cout<<endl;
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<=m;j++)
            {
                cout<<mx[i][j]<<" ";
            }
            cout<<endl;
        }*/
        printf("Case #%d: %lld\n",_,ans);
    }
}
/*
10
3 3
1 -2 -3
2 3 1
-1 -2 1
6 7 8
*/
