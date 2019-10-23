#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
const int N = 2e5+5;
struct Edge
{
    int to,next;

} edge[N];
int head[N],tot;
int low[N],dfn[N],sta[N];
int id,top;
int block;//点双连通分量的个数
bool insta[N];
bool ok[N];//标记
int tmp[N];//暂时存储双连通分量中的点
int cc;//tmp 的计数
int bridge;
void add(int u,int v)
{
    edge[tot].to = v;
    edge[tot].next = head[u];
    head[u] = tot++;
}
int num,ans;
void calc()
{
    for(int i=0; i<cc; i++)
    {
        for(int j=head[tmp[i]]; ~j; j=edge[j].next)
        {
            int v=edge[j].to;
            if(ok[v])
                num++;
        }
    }
    num/=2;
}
void Tarjan(int u,int pre)
{
    int v;
    low[u] = dfn[u] = ++id;
    sta[top++] = u;
    insta[u] = true;
    int pre_cnt = 0;
    for(int i = head[u]; i != -1; i = edge[i].next)
    {
        v = edge[i].to;
        if(v == pre && pre_cnt == 0)
        {
            pre_cnt++;
            continue;
        }
        if( !dfn[v] )
        {
            Tarjan(v,u);
            if(low[u] > low[v])low[u] = low[v];
            if(low[v]>dfn[u])
                bridge++;
            if( low[v] >= dfn[u])
            {
                block++;
                int vn;
                cc = 0;
                memset(ok,false,sizeof(ok));
                //      cout<<"sta:"<<endl;
                do
                {
                    vn = sta[--top];
                    insta[vn] = false;
                    ok[vn] = true;
                    tmp[cc++] = vn;
                    //             cout<<vn<<" ";
                }
                while( vn!=v );
                //           cout<<u<<endl;
                ok[u] = 1;
                num=0;
                tmp[cc++]=u;
                calc();
                if(num>cc)
                {
                    ans+=num;
                }
           //              cout<<"hh:"<<num<<" "<<ans<<" "<<cc<<endl;
            }
        }
        else if(insta[v] && low[u] > dfn[v])
            low[u] = dfn[v];
    }
}
void solve(int n)
{
    memset(dfn,0,sizeof(dfn));
    memset(insta,false,sizeof(insta));
    memset(low,0,sizeof(low));
    id = block = top = 0;
    for(int i = 1; i <= n; i++)
        if(!dfn[i])
            Tarjan(i,-1);
    printf("%d %d\n",bridge,ans);
}
void init()
{
    tot = 0;
    memset(head,-1,sizeof(head));
    bridge=ans=0;
}
int main()
{
    int n,m;
    int u,v;
    while(scanf("%d%d",&n,&m)==2)
    {
        if(n==0 && m==0)break;
        init();
        while(m--)
        {
            scanf("%d%d",&u,&v);
            u++,v++;
            add(u,v),add(v,u);
        }
        solve(n);
    }
    return 0;
}
