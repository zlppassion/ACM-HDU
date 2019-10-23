#include <iostream>
#include<bits/stdc++.h>
using namespace std;
const int maxn=200005;
bool vis[maxn];
int maxnum[maxn];//代表在该数量下的最大值
int maxsum;
struct node
{
    int num;
    int sum;
}a[maxn];
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        maxsum=0;
        memset(vis,false,sizeof(vis));
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i].num);
            a[i].sum++;
        }
        for(int i=0;i<n;i++)
        {
            int t1=a[i].num,t2=a[i].sum;//值，数量
            if(!vis[t1])
            {
                vis[t1]=1;
                if(maxnum[t2]<t1*t2)
                {
                    maxnum[t2]=t1*t2;
                }
                if(maxsum<t2)
                {
                    maxsum=t2;
                }

            }
        }
        int ans=0;
        for(int i=1;i<=maxsum;i++)
        {

        }

    }
    return 0;
}
