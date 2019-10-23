#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll maxn=10010;
ll n,k,q=1;
ll b[maxn],ans[maxn];
struct node
{
    ll p,t;
} a[maxn]; //用结构体排序方便

bool cmp(node a,node b)
{
    return a.p>b.p;    //因逆推，所以从大到小
}
int main()//开始了
{

    scanf("%lld %lld",&n,&k);
    for(ll i=1; i<=k; i++)
    {
        scanf("%lld %lld",&a[i].p,&a[i].t);
        b[a[i].p]++;//b数组求了以a[i].p的开始时间的任务数
    }
    sort(a+1,a+k+1,cmp);//排序
    for(ll i=n; i>0; i--) //注意是逆推{
        if(b[i]==0)//说明本时刻没有任务，所以空闲时间为继承下一时刻的空闲时间+1
            ans[i]=ans[i+1]+1;
        else//本时刻有任务
        {
            for(ll j=1; j<=b[i]; j++)//注意b[i]是以i时间开始的任务的任务数量！！！
            {
                if(ans[i+a[q].t]>ans[i])//更新最大空闲时间,i+a[q].t算的就是结束时间
                    ans[i]=ans[i+a[q].t];
                q++;
            }
        }

//解方程
    printf("%lld",ans[1]);//结果存在第一位，输出
    return 0;
}
