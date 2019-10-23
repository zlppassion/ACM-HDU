/*高玩小Q不仅喜欢玩寻宝游戏，还喜欢一款升级养成类游戏。在这个游戏的世界地图中一共有n个城镇，编号依次为1到n。

这些城镇之间有m条单向道路，第i 条单项道路包含四个参数ui,vi,ai,bi，表示一条从ui号城镇出发，在vi号城镇结束的单向道路，
因为是单向道路，这不意味着小Q可以从vi沿着该道路走到ui。小Q的初始等级level为1，每当试图经过一条道路时，需要支付
cost=log2level+ailevel点积分，并且经过该道路后，小Q的等级会提升ai级，到达level+ai级。但是每条道路都会在一定意义上歧视低消费玩家
，准确地说，如果该次所需积分cost<bi，那么小Q不能经过该次道路，也不能提升相应的等级。

注意：本游戏中等级为正整数，但是积分可以是任意实数。

小Q位于1号城镇，等级为1，现在为了做任务要到n号城镇去。这将会是一次奢侈的旅行，请写一个程序帮助小Q找到需要支付的总积分最少的
一条路线，或判断这是不可能的。


Input
第一行包含一个正整数T(1≤T≤30)，表示测试数据的组数。

每组数据第一行包含两个整数n,m(2≤n≤100000,1≤m≤200000)，表示城镇数和道路数。

接下来m行，每行四个整数ui,vi,ai,bi(1≤ui,vi≤n,ui≠vi,0≤ai≤109,0≤bi≤60)，分别表示每条单向道路。


Output
对于每组数据，输出一行一个整数，即最少所需的总积分的整数部分，如：4.9999输出4，1.0输出1。若不存在合法路线请输出−1。


Sample Input
1
3 3
1 2 3 2
2 3 1 6
1 3 5 0


Sample Output
2*/
#include<bits/stdc++.h>
using namespace std;
const int maxn = 1000050;
const long long INF = 1ll<<61;  //这里一开始用了0x3f3f3f3f...sb了

struct qnode
{
    int v;
    long long c;//c就是代表等级
    qnode(int v=0,long long c=0):v(v),c(c){}
    bool operator <(const qnode &r)const
    {
        return c>r.c;
    }
};
struct Edge
{
    int to;//to即是v
    int w,MIN;//w即是ai,MIN即是bi
    Edge(int to,int w,int MIN):to(to),w(w),MIN(MIN){}
};

vector<Edge>E[maxn];
bool vis[maxn];
long long dis[maxn];

void Dijstra(int n,int start)
{
    memset(vis,false,sizeof(vis));    //nima,一开始赋值成-1了....
    for(int i=1;i<=n;i++)
        dis[i] = INF;//dis[i]相当于level
    priority_queue<qnode> que;//
     while(!que.empty()) que.pop();
   dis[start] = 1;//初始等级为1
    que.push(qnode(start,1));
    qnode tmp;
    while(!que.empty())
    {
        tmp = que.top();//当前节点
        que.pop();
        int u = tmp.v;//当前节点的编号
        if(vis[u])
            continue;
        vis[u] = 1;
        for(int i=0;i<E[u].size();i++)
        {
            int v = E[u][i].to;//当前节点的“对象”，可到达的那一边
            int a = E[u][i].w;//到达那边可增加的等级
           //if()
        if(log2((dis[u]+a*1.0) / dis[u]*1.0)<E[u][i].MIN)
            //if((a/dis[u])<E[u][i].MIN)     //这里不乘1.0也可以
                continue;
            if(!vis[v]&&dis[v]>dis[u]+a)   //这里的！VIS重要
            {
                dis[v] = dis[u] + a;
                que.push(qnode(v,dis[v]));
            }
        }
    }
    if(dis[n]==INF)
        printf("-1\n");
    else
        printf("%d\n",(int)log2(dis[n]*1.0));
}

int main()
{
    int t,m,u,v,n;
    int a,b;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
            E[i].clear();
        for(int i=0;i<m;i++)
        {
            scanf("%d%d%d%d",&u,&v,&a,&b);
            //b=(1ll<<b)-1;
            E[u].push_back(Edge(v,a,b));
        }
        Dijstra(n,1);
    }
    return 0;
}
