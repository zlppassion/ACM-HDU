#include<iostream>
#include<cstdio>
using namespace std;
/*以例题来说，平均张数为10，原张数变为-1，-2,+7，-4，因为没有为0的数，所以从最左边出发，将-1移动到-2中，
变为0，-3，+7,4，再讲-3向右移动……一次类推，直到全为0为止。
每移动一次，步数便加1。关键是，负数怎么移动，其实，移动-x张牌，其实就是从另一堆中移动x张牌，步数相同。*/
int a[105];
int main()
{
    int n;
    int sum=0,x=0,ans=0;
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
        sum+=a[i];
    }
    x=sum/n;
    for(int i=1; i<=n; i++)
        a[i]-=x;
    for(int i=1; i<=n; i++)
    {
        if(a[i]==0) continue;
        a[i+1]+=a[i];
        ans++;
    }
    cout<<ans<<endl;
    return 0;
}
