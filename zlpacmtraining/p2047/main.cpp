#include<bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
#define ll long long
const int N=105;
const int mod=1e9+7;
const double eps=1e-8;
const double PI = acos(-1.0);
#define lowbit(x) (x&(-x))
ll g[N][N],a[N][N];
int main()
{
    std::ios::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    memset(g,inf,sizeof(g));
    for(int i=1;i<=n;i++)
    {
        g[i][i]=0;
    }
    for(int i=1;i<=m;i++)
    {
        ll u,v,w;
        cin>>u>>v>>w;
        g[u][v]=g[v][u]=w;
        a[u][v]=a[v][u]=1;
    }
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(g[i][j]>=g[i][k]+g[k][j])
                {
                    g[i][j]=g[i][k]+g[k][j];
                    a[i][j]+=a[i][k]*a[k][j];
                }
            }
        }
    }
   /* for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }*/
    double ans=0;
    for(int i=1;i<=n;i++)
    {
        ans=0;
        for(int j=1;j<=n;j++)
        {
            for(int k=1;k<=n;k++)
            {
                if(g[j][i]+g[i][k]==g[j][k]&&a[j][k])
                {
                    ans+=a[j][i]*a[i][k]*1.0/(1.0*a[j][k]);
                }
            }
        }
        cout<<fixed<<setprecision(3)<<ans<<endl;
    }
    return 0;
}
