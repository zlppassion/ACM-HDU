#include<cstdio>
#define min(x,y) x<y ? x : y
int n,A,B,ans=0x7ffffff;
int a[205];
bool vis[205];//is_land���������洢��û��ȥ��
void dfs(int now,int sum)//now�������ڵ�¥�㣬sum������ť�Ĵ���
{
    if(now==B) ans=min(ans,sum);//���������¥�����¼��
    else if(sum<=ans)//һ����֦�������ǰ��sum���ڴ𰸣���ô�������ܳ�Ϊ�𰸡�
    {
        vis[now]=true;//��¼������ǰ¥��
        if(now+a[now]<=n && !vis[now+a[now]]) dfs(now+a[now],sum+1);
        if(now-a[now]>=1 && !vis[now-a[now]]) dfs(now-a[now],sum+1);//dfs�ֱ����ϡ�����
        vis[now]=false;//����
    }
}
int main()
{
    scanf("%d %d %d",&n,&A,&B);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    vis[A]=true;
    dfs(A,0);
    if(ans!=0x7ffffff) printf("%d",ans);
    else printf("-1");//�ӵ���һ���ύ��-1�ж�
    return 0;//����
}
