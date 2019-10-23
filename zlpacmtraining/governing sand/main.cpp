#include<bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
#define ll long long
const int N=1e5+5;
const int mod=1e9+7;
const double eps=1e-8;
const double PI = acos(-1.0);
#define lowbit(x) (x&(-x))
struct node
{
    ll h,c,p;
    bool operator<(node b)
    {
        return h<b.h;
    }
} g[N];
ll s[N],c[N],p[N];
int main()
{
    std::ios::sync_with_stdio(false);
    ll n;
    while(cin>>n)
    {
        for(int i=0; i<=n+1; i++)s[i]=p[i]=0;
        for(int i=1; i<=200; i++) c[i]=0;
        for(int i=1; i<=n; i++)
        {
            cin>>g[i].h>>g[i].c>>g[i].p;
        }
        sort(g+1,g+1+n);//按照高度从低到高排序
        for(int i=n; i>=1; i--)
        {
            s[i]=g[i].c*g[i].p+s[i+1];//总花费的后缀和
            p[i]=g[i].p+p[i+1];//总高度的后缀和
        }
        ll ans=1e18;
        for(ll i=1; i<=n; i++)
        {
            ll j,k;
            ll qq=g[i].p;
            for(j=i+1; j<=n; j++)
            {
                if(g[j].h!=g[i].h)//这里是判断前后的不同种类的树的高度是否相同
                    break;
                qq+=g[j].p;//如果高度相同，就累加到qq上
            }
            k=i;
            i=j-1;//此时的k和i就相当于同样高度的起始位置和结束位置
            ll res=0,pp=p[1];
            res+=s[i+1];//计算在这之后的需要的花费
            pp-=p[i+1];
            int flag=0;
    //            cout<<i<<" "<<pp<<" "<<qq<<endl;

            if(2*qq<=pp)
                for(j=1; j<=200; j++)
                {
                    if(2*qq>pp-c[j])
                    {
                        res+=(c[j]-(2*qq+c[j]-pp-1))*j;
                        flag=1;
                        break;
                    }
                    else
                    {
                        res+=c[j]*j;
                        pp-=c[j];
                    }
                }
            else
                flag=1;
               for(; k<=i; k++)
                   c[g[k].c]+=g[k].p;
            //      cout<<i<<' '<<res<<endl;
     //       cout<<i<<" "<<res<<endl;
            if(flag)
                ans=min(ans,res);
        }
        cout<<ans<<endl;
    }
    return 0;
}
/*
3
1 1 1
2 2 2
3 3 3
*/
