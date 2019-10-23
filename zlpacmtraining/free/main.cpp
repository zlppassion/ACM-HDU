#pragma GCC optimize(3)
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn  =  1005;
int n,m,s,t,k;
struct  edge
{
    int to,cost;
    edge(){}
    edge(int to,int cost):to(to),cost(cost){}
};
struct  node
{
    int v,w,cnt;
    node(){}
    node(int v,int w,int cnt):v(v),w(w),cnt(cnt){}
    bool operator<(const node&ano)const{return w>ano.w;}
};
int dis[maxn][maxn];//表示到i节点时 把j条边的权值变为0的最短距离
//bool vis[maxn][maxn];
vector<edge> G[maxn];
priority_queue<node> pq;//把最小的放在队首
void addG(int u,int v,int w)
{
    G[u].push_back(edge(v,w));
    G[v].push_back(edge(u,w));
}
void dijkstra()
{
    memset(dis,0x3f,sizeof(dis));
   // memset(vis,false,sizeof(vis));
    dis[s][0] = 0;//s到本身时，最短距离为0，把0条边的权值变为0
    pq.push(node(s,0,0));
    while(!pq.empty())
    {
        const node top = pq.top();//pq的三个属性分别为v,w,cnt
        pq.pop();
        int u = top.v;
        int nowcnt = top.cnt;//表示已经有多少条的边权变为0
      //  if(vis[u][nowcnt]==true)continue;
      //  vis[u][nowcnt] = true;
        for(int i = 0;i<(int)(G[u].size());i++)
        {
            int v = G[u][i].to;//连接边
            int w = G[u][i].cost;//该边权值
            //用免费机会
            if(nowcnt<k&&dis[v][nowcnt+1]>dis[u][nowcnt])
            {
                  dis[v][nowcnt+1]=dis[u][nowcnt];//更新
                  pq.push(node(v,dis[v][nowcnt+1],nowcnt+1));
            }
            //不用免费机会
            if(dis[v][nowcnt]>dis[u][nowcnt]+w)
            {
                dis[v][nowcnt]=dis[u][nowcnt]+w;
                pq.push(node(v,dis[v][nowcnt],nowcnt));
            }
        }

    }
}
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>n>>m>>s>>t>>k;
    while(m--)
    {
        int u,v,w;
        cin>>u>>v>>w;
        addG(u,v,w);
    }
    int ans = 0x3f3f3f3f;
    dijkstra();
    for(int i = 0;i<=k;i++)
    {
        ans = min(ans,dis[t][i]);
    }
    cout<<ans<<endl;
    return 0;
}
