#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
#define ls ft[rt].l
#define rs ft[rt].r
const int N = 200010;
const int inf = 0x3f3f3f3f;
const int mod=1000000;
#define ll long long
int Rand() //随机数
{
    static int seed = 703;
    return seed=(int)(seed*48271LL%2147483647);
}

int root,tot;

struct fhq_treap
{
    int l,r;
    int v,rnd;
    int sz;
    int mi,rev,lzy;
} ft[N];

void pushUp( int rt ) //上推
{
    if ( !rt )
        return;
    ft[rt].mi = min ( ft[rt].v, min( ft[ls].mi, ft[rs].mi ) );
    ft[rt].sz = ft[ls].sz+ft[rs].sz+1;
}

void pushDown( int rt ) //下推标记
{
}

void build( int &rt, int v ) //创建新结点
{
    rt = ++tot;
    ft[rt].l = 0;
    ft[rt].r = 0;
    ft[rt].v = v;
    ft[rt].rnd = Rand();
    ft[rt].sz = 1;
    ft[rt].mi = v;
    ft[rt].rev = 0;
    ft[rt].lzy = 0;
}

void split( int rt, int &l, int &r, int v ) //将以rt为根的树分裂为以l和r为根的子树
{
    if ( v==0 )
        l = 0,r = rt;
    else if ( v==ft[rt].sz )
        l = rt,r = 0;
    else if ( v<=ft[ls].sz )
        pushDown( r=rt ),split( ls, l, ls, v ),pushUp( rt );
    else
        pushDown( l=rt ),split( rs, rs, r, v-ft[ls].sz-1 ),pushUp( rt );
}

void merge( int &rt, int l, int r ) //将以l和r为根的子树合并成以rt为根的树
{
    if ( l==0||r==0 )
        rt = l+r;
    else if ( ft[l].rnd<ft[r].rnd )
        pushDown( rt=l ),merge( rs, rs, r ),pushUp( rt );
    else
        pushDown( rt=r ),merge( ls, l, ls ),pushUp( rt );
}

int Rank(int rt, int val) //查排名
{
    if(!rt) return 0;
    if(ft[rt].v >= val) return Rank(ft[rt].l, val);
    return Rank(ft[rt].r, val) + ft[ft[rt].l].sz + 1;
}

int findKth(int k)  //找排名为k的数
{
    int x, y, z, ans;
    split(root, x, y, k - 1);
    split(y, y, z, 1);
    ans = ft[y].v;
    merge(y, y, z);
    merge(root, x, y);
    return ans;
}

void delData( int v ) //删除数v
{
    int x,y,z;
    int k=Rank(root,v)+1;
    split( root, x, y, k );
    split( x, x, z, k-1 );
    merge( root, x, y );
}

void insert(int val) //尾插
{
    int k = Rank(root, val), x, y, z;
    split(root, x, y, k);
    build(z,val);
    merge(x, x, z);
    merge(root, x, y);
}
int main()
{
    int n,m,op;
    while(~scanf("%d",&n))
    {
        tot = root = 0;
        ll ans=0,now=0;
        for ( int i=1,x ; i<=n ; i++ )
        {
            scanf ( "%d%d", &op,&x );
            if(now==0) insert(x);
            else if(now>0)
            {
                if(op)
                    insert(x);
                else
                {
                    insert(x);
                    int g=inf,t=Rank(root,x)+1;
                    if(findKth(t+1)!=0)
                        g=findKth(t+1);
                    if(t>1&&(abs(x-findKth(t-1))<=abs(g-x)))
                        g=findKth(t-1);
                    if(g==inf)
                    {
                        continue;
                    }
                    delData(g);
                    delData(x);
                    ans+=abs(g-x);
                }
            }
            else if(now<0)
            {
                if(!op)
                    insert(x);
                else
                {
                    insert(x);
            //        cout<<Rank(root,4)+1<<endl;
                    int g=inf,t=Rank(root,x)+1;
                    if(findKth(t+1)!=0)
                        g=findKth(t+1);
                    if(t>1&&(abs(x-findKth(t-1))<=abs(g-x)))
                        g=findKth(t-1);
                    if(g==inf)
                    {
                        continue;
                    }
                    delData(g);
                    delData(x);
                    ans+=abs(g-x);
                }
            }
            now+=(op?1:-1);
        }
        cout<<ans<<endl;
    }
    return 0;
}
