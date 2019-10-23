#include<bits/stdc++.h>
using namespace std;
int n,head,k,p,pre[100005],nxt[100005],i,m,x,exist[100005];
int main()
{
    scanf("%d",&n);
    head=1;
    for(i=2;i<=n;i++)
    {
        scanf("%d%d",&k,&p);
        if(!p)//插左边
        {
            if(k==head) head=i;
            pre[i]=pre[k];
            nxt[i]=k;
            nxt[pre[k]]=i;
            pre[k]=i;
        }
        if(p)//插右边
        {
            pre[i]=k;
            nxt[i]=nxt[k];
            pre[nxt[k]]=i;
            nxt[k]=i;
        }
    }
    scanf("%d",&m);//删除m个数
    for(i=1;i<=m;i++)
    {
        scanf("%d",&x);
        if(x==head) head=nxt[x];
        if(exist[x]) continue;//如果已经删除了
        nxt[pre[x]]=nxt[x];
        pre[nxt[x]]=pre[x];
        exist[x]=1;//标记被删除
    }
    for(i=head;i;i=nxt[i])
        printf("%d ",i);
    return 0;
}
