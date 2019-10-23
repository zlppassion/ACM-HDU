#pragma GCC optimize(3)
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/rope>
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;
#define ll long long
#define ld double
#define ull unsigned long long
#define rep(i,a,b) for(int i=a;i<b;i++)
#define Rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=b-1;i>=a;i--)
#define Per(i,a,b) for(int i=b;i>=a;i--)
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
#define CASET int ___T; scanf("%d", &___T); for(int cs=1;cs<=___T;cs++)
#define Read(x) scanf("%d",&x)
#define ReadD(x) scanf("%lf",&x)
#define ReadLL(x) scanf("%lld",&x)
#define ReadLD(x) scanf("%llf",&x)
#define Write(x) printf("%d\n",x)
#define WriteD(x) printf("%f\n",x)
#define WriteLL(x) printf("%lld\n",x)
#define WriteLD(x) printf("%Lf\n",x)
#define IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
const ld pi=acos(-1);
const ll mod=1e9+7;
#define lowbit(x) (x&(-x))
const ld eps=1e-6;
const int maxn=1e5+10;
const int INF=0x3f3f3f3f;
const double e=2.718281828459045;
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
struct Point
{
    ld x,y;
    Point(ld x=0,ld y=0):x(x),y(y) {}
} p[5];
signed main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int w,h,a,b,c;
        //cin>>w>>h>>a>>b>>c;
        scanf("%d%d%d%d%d",&w,&h,&a,&b,&c);
        if(a>=b&&a>=c)
        {
            p[1]= {0,0};
            if(a>=w)
            {
                ld yy=sqrt((ld)a*a-w*w);
                p[2]=Point(w,yy);
            }
            else
            {
                p[2]= {a,0};
            }
            ld A=2*(p[1].x-p[2].x),B=2*(p[1].y-p[2].y),C=b*b-c*c+p[1].x*p[1].x+p[1].y*p[1].y-(p[2].x*p[2].x+p[2].y*p[2].y);
            ld l=0,r=h,mid;
            while(1)
            {
                mid=(l+r)/2;
                ld tt=(ld)c*c-(((C-B*mid)/A)-p[1].x)*(((C-B*mid)/A)-p[1].x);
                if(fabs(tt)<eps)
                    tt=0;
                ld temp=(mid-p[1].y-sqrt(tt));
               // cout<<c<<' '<<tt<<' '<<(C-B*mid)/A-p[1].x<<' '<<temp<<endl;
                if(fabs(temp)<eps)
                    break;
                else if(temp>0)
                {
                    r=mid;
                }
                else
                {
                    l=mid;
                }
            }
            ld xxx=(C-B*mid)/A;
            p[3]={xxx,mid};
        }
        else if(b>=a&&b>=c)
        {
            p[1]= {0,0};
            if(a>=w)
            {
                ld yy=sqrt((ld)a*a-w*w);
                p[2]=Point(w,yy);
            }
            else
            {
                p[2]= {a,0};
            }
            ld A=2*(p[1].x-p[2].x),B=2*(p[1].y-p[2].y),C=b*b-c*c+p[1].x*p[1].x+p[1].y*p[1].y-(p[2].x*p[2].x+p[2].y*p[2].y);
            ld l=0,r=h,mid;
            while(1)
            {
                mid=(l+r)/2;
                ld tt=(ld)c*c-(((C-B*mid)/A)-p[1].x)*(((C-B*mid)/A)-p[1].x);
                if(fabs(tt)<eps)
                    tt=0;
                ld temp=(mid-p[1].y-sqrt(tt));
               // cout<<c<<' '<<tt<<' '<<(C-B*mid)/A-p[1].x<<' '<<temp<<endl;
                if(fabs(temp)<eps)
                    break;
                else if(temp>0)
                {
                    r=mid;
                }
                else
                {
                    l=mid;
                }
            }
            ld xxx=(C-B*mid)/A;
            p[3]={xxx,mid};
            swap(p[2],p[3]);
        }
        else
        {
            swap(a,c);
            p[1]= {0,0};
            if(a>=w)
            {
                ld yy=sqrt((ld)a*a-w*w);
                p[2]=Point(w,yy);
            }
            else
            {
                p[2]= {a,0};
            }
            ld A=2*(p[1].x-p[2].x),B=2*(p[1].y-p[2].y),C=b*b-c*c+p[1].x*p[1].x+p[1].y*p[1].y-(p[2].x*p[2].x+p[2].y*p[2].y);
            ld l=0,r=h,mid;
            while(1)
            {
                mid=(l+r)/2;
                ld tt=(ld)c*c-(((C-B*mid)/A)-p[1].x)*(((C-B*mid)/A)-p[1].x);
                if(fabs(tt)<eps)
                    tt=0;
                ld temp=(mid-p[1].y-sqrt(tt));
               // cout<<c<<' '<<tt<<' '<<(C-B*mid)/A-p[1].x<<' '<<temp<<endl;
                if(fabs(temp)<eps)
                    break;
                else if(temp>0)
                {
                    r=mid;
                }
                else
                {
                    l=mid;
                }
            }
            ld xxx=(C-B*mid)/A;
            p[3]={xxx,mid};
            swap(p[1],p[3]);
        }
        //cout<<fixed<<setprecision(8)<<fabs(p[1].x)<<' '<<fabs(p[2].x)<<' '<<fabs(p[3].x)<<endl;
        //cout<<fixed<<setprecision(8)<<fabs(p[1].y)<<' '<<fabs(p[2].y)<<' '<<fabs(p[3].y)<<endl;
        printf("%.8f %.8f %.8f\n",fabs(p[1].x),fabs(p[2].x),fabs(p[3].x));
        printf("%.8f %.8f %.8f\n",fabs(p[1].y),fabs(p[2].y),fabs(p[3].y));
    }
    return Accepted;
}
