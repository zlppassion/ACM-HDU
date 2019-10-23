//author Numb
#pragma GCC optimize(3)
#pragma comment(linker, "/STACK:1024000000,1024000000")
#define Hello the_cruel_world!
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/rope>
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
void test()
{
    cerr<<"\n";
}
template<typename T,typename... Args>void test(T x,Args... args)
{
    cerr<<x<<" ";
    test(args...);
}
#define il inline
#define ll long long
#define ld long double
#define ull unsigned long long
#define rep(i,a,b) for(register int i=a;i<b;i++)
#define Rep(i,a,b) for(register int i=a;i<=b;i++)
#define per(i,a,b) for(register int i=b-1;i>=a;i--)
#define Per(i,a,b) for(register int i=b;i>=a;i--)
#define pb push_back
#define eb emplace_back
#define MP make_pair
#define fi first
#define se second
#define SZ(x) (x).size()
#define LEN(x) (x).length()
#define ALL(X) (X).begin(), (X).end()
#define MS0(X) memset((X), 0, sizeof((X)))
#define MS1(X) memset((X), -1, sizeof((X)))
#define MS(X,a) memset((X),a,sizeof(X))
#define CASET int ___T; scanf("%d", &___T); for(register int cs=1;cs<=___T;cs++)
#define ind(x) scanf("%d",&x)
#define inlf(x) scanf("%lf",&x)
#define inll(x) scanf("%lld",&x)
#define inllf(x) scanf("%llf",&x)
#define outd(x) printf("%d\n",x)
#define outf(x) printf("%f\n",x)
#define outlld(x) printf("%lld\n",x)
#define outLf(x) printf("%Lf\n",x)
#define IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
constexpr ld pi=acos(-1);
constexpr ll mod=1e9+7;
#define lowbit(x) (x&(-x))
constexpr ld eps=1e-6;
constexpr int maxn=1e5+10;
constexpr int INF=0x3f3f3f3f;
constexpr double e=2.718281828459045;
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<PII> VPII;
typedef pair<LL,LL> PLL;
typedef vector<PLL> VPLL;
typedef vector<int> VI;
typedef pair<int,int> PII;
#define Accepted 0
inline ll quick(ll a,ll b,ll m)
{
    ll ans=1;
    while(b)
    {
        if(b&1)ans=(a*ans)%m;
        a=(a*a)%m;
        b>>=1;
    }
    return ans;
}
inline ll gcd(ll a,ll b)
{
    return b?gcd(b,a%b):a;
}



struct edge
{
    int v,w;
};
vector<edge> E[maxn];
bool vis[maxn];
ll mp[maxn][2019];
ll ans=0;
void dfs(int rt)
{
    vis[rt]=1;
    for(edge e:E[rt])
    {
        if(!vis[e.v])
        {
            dfs(e.v);
            for(int k=0; k<2019; k++)
            {
                if(mp[e.v][k])
                {
                    ans+=mp[rt][(2019-(e.w+k)%2019)%2019]*mp[e.v][k];
                    mp[rt][(k+e.w)%2019]+=mp[e.v][k];
                }
            }
        }
    }
    ans+=mp[rt][0];
    mp[rt][0]++;
}
signed main()
{
    int n;
    while(~scanf("%d",&n))
    {
        ans=0;
        for(int i=1; i<=n; i++)
        {
            for(int j=0; j<2019; j++)
                mp[i][j]=0;
            E[i].clear(),vis[i]=0;
        }
        Rep(i,1,n-1)
        {
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            E[a].pb({b,c});
            E[b].pb({a,c});
        }
        dfs(1);
        printf("%lld\n",ans);
    }
    return Accepted;
}
