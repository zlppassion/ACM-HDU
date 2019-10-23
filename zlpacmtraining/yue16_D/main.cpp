#include<bits/stdc++.h>
using namespace std;
const int maxn=2e6+5;
struct node{
    int num,pos;
}e[maxn];
bool cmp(node a,node b)//排序
{
    if(a.num==b.num)
        return a.pos>b.pos;//如果前缀和相等，则按照位置从大到小排
    return a.num<b.num;//前缀和从小到大排序
}
/*求一下前缀和num，即要求满足num[x]-num[y]>0的最大的(x-y)，那么我们从小到大排个序
从左到右扫一遍，记录num的最小的position，每次拿当前的position减去最小的position来更新一下结果，
排序的时候要考虑一下num[0]，即不包含任何一个数的num[0]（值为0）;
*/
int main()
{
    int n,x;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&x);
        e[i].num=x+e[i-1].num;//前缀和
        e[i].pos=i;//位置
    }
    n++;
    sort(e+1,e+n+1,cmp);
    int minx=n;
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        minx=min(minx,e[i].pos);
        if(e[i].pos>minx)
            ans=max(ans,e[i].pos-minx);
    }
    printf("%d\n",ans);
    return 0;
}
