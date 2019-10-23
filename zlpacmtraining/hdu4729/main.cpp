#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define il inline
const int inf = 0x3f3f3f3f, N = 1e5 + 5;
int n, m, T;
//适用于正负数,(int,long long,float,double)
template <class T>
il bool read(T &ret)
{
    char c;
    int sgn;
    T bit=0.1;
    if(c=getchar(),c==EOF) return 0;
    while(c!='-'&&c!='.'&&(c<'0'||c>'9')) c=getchar();
    sgn=(c=='-')?-1:1;
    ret=(c=='-')?0:(c-'0');
    while(c=getchar(),c>='0'&&c<='9') ret=ret*10+(c-'0');
    if(c==' '||c=='\n')
    {
        ret*=sgn;
        return 1;
    }
    while(c=getchar(),c>='0'&&c<='9') ret+=(c-'0')*bit,bit/=10;
    ret*=sgn;
    return 1;
}
// 线段树
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
int mi[N << 2];
void pushUp(int rt)
{
    mi[rt] = max(mi[rt << 1], mi[rt << 1 | 1]);
}
void build(int l, int r, int rt)
{
    mi[rt] = 0;
    if (l == r) return;
    int m = (l + r) >> 1;
    build(lson);
    build(rson);
}
int query(int L, int R, int l, int r, int rt)
{
    if (L <= l && r <= R)
        return mi[rt];
    int m = (l + r) >> 1;
    int ret = inf;
    if (L <= m) ret = min(ret, query(L, R, lson));
    if (R > m) ret = min(ret, query(L, R, rson));
    return ret;
}
void update(int p, int x, int l, int r, int rt)
{
    if (l == r)
    {
        mi[rt] = x;
        return;
    }
    int m = (r + l) >> 1;
    if (p <= m) update(p, x, lson);
    else update(p, x, rson);
    pushUp(rt);
}

// 树链剖分
struct Edge
{
    int to, next;
} edge[N * 2];

int head[N], tot;
int top[N];  // top[v]即v所在重链的顶端结点
int fa[N];   // 父节点
int deep[N]; // 深度
int num[N];  // num[v] 以v为根的子树结点数
int p[N];    // p[v]为v的dfs位置
int fp[N];   // 与p相反
int son[N];  // 重子编号
int pos;

void init()
{
    tot = 0;
    pos = 0;
    memset(head,-1,sizeof(head));
    memset(son, -1,sizeof(son));
}

void add(int u, int v)
{
    edge[tot].to = v;
    edge[tot].next = head[u];
    head[u] = tot++;
}

void dfs1(int u, int pre, int d)
{
    deep[u] = d;
    fa[u] = pre;
    num[u] = 1;
    for (int i = head[u]; i != -1; i = edge[i].next)
    {
        int v = edge[i].to;
        if (v != pre)
        {
            dfs1(v, u, d + 1);
            num[u] += num[v];
            if (son[u] == -1 || num[v] > num[son[u]])
                son[u] = v;
        }
    }
}

void dfs2(int u, int sp)
{
    top[u] = sp;
    p[u] = pos++;
    fp[p[u]] = u;
    if (son[u] == -1)
        return;
    dfs2(son[u], sp);
    for (int i = head[u]; i != -1; i = edge[i].next)
    {
        int v = edge[i].to;
        if (v != son[u] && v != fa[u])
            dfs2(v, v);
    }
}

int queryMin(int u, int v)
{
    int f1 = top[u], f2 = top[v];
    int tmp = inf;
    while (f1 != f2)
    {
        if (deep[f1] < deep[f2])
        {
            swap(f1, f2);
            swap(u, v);
        }
        tmp = min(tmp, query(p[f1], p[u], 0, pos - 1, 1));
        u = fa[f1];
        f1 = top[u];
    }
    if (u == v) return tmp;
    if (deep[u] > deep[v]) swap(u, v);
    return min(tmp, query(p[son[u]], p[v], 0, pos - 1, 1));
}

int e[N][3],all=0;
bool fun(ll L,ll R,ll l,ll r,ll rt,ll x)
{
    if(L<=l&&r<=R&&mi[rt]>=x)
    {
        return true;
    }
    if(l==r)
    {
        if(mi[rt]>=x)
            return true;
        all-=(x-mi[rt]);
        return all>=0;
    }
    int ret = 1;
    int m=(l+r)>>1;
    if (L <= m) ret &= fun(L, R, lson,x);
    if (R > m) ret &= fun(L, R, rson,x);
    return ret;
}
bool check(ll u,ll v,ll x)
{
    int f1 = top[u], f2 = top[v];
    while (f1 != f2)
    {
        if (deep[f1] < deep[f2])
        {
            swap(f1, f2);
            swap(u, v);
        }
        if(!fun(p[f1], p[u], 0, pos - 1, 1,x))
            return false;
        u = fa[f1];
        f1 = top[u];
    }
    if (u == v) return true;
    if (deep[u] > deep[v]) swap(u, v);
    return fun(p[son[u]], p[v], 0, pos - 1, 1,x);
}
int main()
{
    read(T);
    int cs=0;
    while (T--)
    {
        printf("Case #%d:\n",++cs);
        init();
        read(n),read(m);
        for(int i=0; i<n-1; i++)
        {
            read(e[i][0]),read(e[i][1]),read(e[i][2]);
            add(e[i][0], e[i][1]);
            add(e[i][1], e[i][0]);
        }
        dfs1(1, 0, 0);
        dfs2(1, 1);
        build(0, pos - 1, 1);
        for(int i=0; i<n-1; i++)
        {
            if (deep[e[i][0]] > deep[e[i][1]])
                swap(e[i][0], e[i][1]);
            update(p[e[i][1]], e[i][2], 0, pos - 1, 1);
        }
        while (m--)
        {
            ll s,t,k,a,b;
            read(s),read(t),read(k),read(a),read(b);
            ll ans=queryMin(s,t);
            if(k<min(a,b))
            {
                printf("%lld\n",ans);
                continue;
            }
            else if(a<=b)
            {
                ans+=k/a;
            }
            else
            {
                ans+=(k-a)/b+1;
                ll l=ans,r=10000,mid;
                while(l<r)
                {
                    mid=(l+r+1)>>1;
                    all=k/b;
                    if(check(s,t,mid))
                    {
                        ans=mid;
                        l=mid;
                    }
                    else
                        r=mid-1;
                }
            }
            printf("%lld\n",ans);
        }
    }
    return 0;
}
