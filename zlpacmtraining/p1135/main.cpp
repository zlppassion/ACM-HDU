#include<cstdio>
#define min(x,y) x<y ? x : y
int n,A,B,ans=0x7ffffff;
int a[205];
bool vis[205];//is_land数组用来存储有没有去过
void dfs(int now,int sum)//now代表现在的楼层，sum代表按按钮的次数
{
    if(now==B) ans=min(ans,sum);//如果到达了楼层则记录答案
    else if(sum<=ans)//一个剪枝：如果当前的sum大于答案，那么它不可能成为答案。
    {
        vis[now]=true;//记录来过当前楼层
        if(now+a[now]<=n && !vis[now+a[now]]) dfs(now+a[now],sum+1);
        if(now-a[now]>=1 && !vis[now-a[now]]) dfs(now-a[now],sum+1);//dfs分别向上、向下
        vis[now]=false;//回溯
    }
}
int main()
{
    scanf("%d %d %d",&n,&A,&B);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    vis[A]=true;
    dfs(A,0);
    if(ans!=0x7ffffff) printf("%d",ans);
    else printf("-1");//坑掉我一次提交的-1判断
    return 0;//结束
}
