#include<bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
#define ll long long
#define il inline
#define re register
const int N=1e6+5;
const int mod=1e9+7;
const double eps=1e-8;
const double PI = acos(-1.0);
#define lowbit(x) (x&(-x))
//������������,(int,long long,float,double)
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
il void out(int x)
{
    if(x>9) out(x/10);
    putchar(x%10+'0');
}
int block,ans=0,cnt[N],pos[N];
int n,m,a[N],Ans[N],qn,un;

struct node
{
    int l,r,id,t;
    bool operator <(node b)
    {
        return (pos[l]<pos[b.l])||(pos[l]==pos[b.l]&&pos[r]<pos[b.r])||(pos[l]==pos[b.l]&&pos[r]==pos[b.r]&&t<b.t);
    }
} q[N];
struct upd
{
    int id,val;
} u[N];

il void add(int x)
{
    if(!cnt[a[x]])ans++;
    cnt[a[x]]++;
}

il void del(int x)
{
    cnt[a[x]]--;
    if(!cnt[a[x]])ans--;
}
il void update(int x,int i)
{
    if(u[x].id>=q[i].l&&u[x].id<=q[i].r)
    {
        del(a[u[x].id]);
        add(u[x].val);
    }
    swap(u[x].val,a[u[x].id]);
}
int i;
int main()
{
    read(n),read(m);
    for(i=1; i<=n; ++i) read(a[i]);
    block=pow(n,2/3);
    for(int i=1; i<=n; i++)
    {
        pos[i]=(i-1)/block+1;
    }
    for(i=1; i<=m; ++i)
    {
        char c;
        scanf("%c",&c);
        if(c=='Q')
        {
            read(q[++qn].l);
            read(q[qn].r);
            q[qn].t=un;
            q[qn].id=qn;
        }
        else
        {
            read(u[++un].id);
            read(u[un].val);
        }
    }
    sort(q+1,q+qn+1);
    int l=0,r=0,t=0;
    for(i=1; i<=qn; ++i)
    {
        int ql=q[i].l,qr=q[i].r;
        while(l<ql)del(l++);
        while(l>ql)add(--l);
        while(r<qr)add(++r);
        while(r>qr)del(r--);
        while(t<q[i].t) update(++t,i);
        while(t>q[i].t) update(t--,i);
        Ans[q[i].id]=ans;
    }
    for(i=1; i<=qn; ++i)out(Ans[i]),printf("\n");
    return 0;
}
/*
10 4
1 1000000 2 1000000 1 1000000 3 1 10 1
*/
