#include<bits/stdc++.h>
#define mid (l+r)/2
using namespace std;

const int N = 2e5+100;
int n, q, sz, num = 0;
int a[N],T[N];
int sum[N<<5], L[N<<5], R[N<<5];

inline int build(int l, int r)
{
    int rt = ++ num;
    sum[rt] = 0;
    if (l < r)
    {
        L[rt] = build(l, mid);
        R[rt] = build(mid+1, r);
    }
    return rt;
}

inline int update(int pre, int l, int r, int x,int d)
{
    int rt = ++ num;
    L[rt] = L[pre];
    R[rt] = R[pre];
    sum[rt] = sum[pre]+d;
    if (l < r)
    {
        if (x <= mid) L[rt] = update(L[pre], l, mid, x,d);
        else R[rt] = update(R[pre], mid+1, r, x,d);
    }
    return rt;
}

inline int query(int u,int l, int r, int k)
{
    if (l == r) return sum[u];
    int ans=0;
    if (mid >= k) ans=query(L[u], l, mid, k);
    else ans=sum[L[u]]+query(R[u], mid+1, r, k);
    return ans;
}
int ans[N];
int main()
{
    int t,cas=0;
    scanf("%d",&t);
    while(t--)
    {
        num=0;
        memset(ans,0,sizeof(ans));
        memset(sum,0,sizeof(sum));
        memset(T,0,sizeof(T));
        memset(L,0,sizeof(L));
        memset(R,0,sizeof(R));
        scanf("%d%d", &n,&q);
        for (int i = 1; i <= n; i ++)
        {
            scanf("%d", &a[i]);
        }
        map<int,int> mp;
        T[0] = build(0, n);
        for (int i = 1; i <= n; i ++)
        {
            if(!mp[a[i]])
            {
                T[i] = update(T[i-1],0,n,i,1);
            }
            else
            {
                int t=update(T[i-1],0,n,mp[a[i]],-1);
                T[i]=update(t,0,n,i,1);
            }
            mp[a[i]]=i;
        }

        int i=0;
        while (q --)
        {
            ++i;
            int x, y;
            scanf("%d%d", &x, &y);
            int xx=x;
            x=min(((x+ans[i-1])%n)+1,((y+ans[i-1])%n)+1);
            y=max(((xx+ans[i-1])%n)+1,((y+ans[i-1])%n)+1);
      //      cout<<x<<" "<<y<<endl;
            ans[i]= query(T[y], 0, n, y)-query(T[y],0,n,x-1);
       //     cout<<"²»Í¬:"<<ans[i]<<endl;
            ans[i]=(ans[i]+1)/2;
            ans[i]+=(x-1);
        //    printf(" %d", ans[i]);
        }
        printf("Case #%d:",++cas);
        for(int j=1;j<=i;j++)
            printf(" %d",ans[j]);
        puts("");
    }

    return 0;
}
