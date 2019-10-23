#include<bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
const int N=1e5+5;
int n;
int q1[N],q2[N],h1,h2,t1,t2,p1[N],p2[N],d;
//q1是最大值队列
//p1是最大值下标队列
//q2是最小值队列
//p2是最小值下标队列
struct node
{
    int x,v;
    bool operator<(node b)
    {
        return x<b.x;
    }
} a[N];
int main()
{
    cin>>n>>d;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i].x>>a[i].v;
    }
    sort(a+1,a+1+n);
    h1=h2=1;
    t1=t2=0;
    int l,r=1,ans=inf;
    for(l=1; l<=n; ++l)
    {
        while(h1<=t1&&p1[h1]<l)//p1是最大值下标队列
            h1++;
        while(h2<=t2&&p2[h2]<l)//p2是最小值下标队列
            h2++;
        for(r; r<=n; r++)
        {
            while(h1<=t1&&q1[t1]<=a[r].v)//q1是最大值队列，维护最大值，保证队列单调递减（所以如果小了就应该删掉），队尾最小
                t1--;
            q1[++t1]=a[r].v;
            p1[t1]=r;
            while(h2<=t2&&q2[t2]>=a[r].v)//q2是最小值队列，维护最小值，保证队列单调递增，队尾最大
                t2--;
            q2[++t2]=a[r].v;
            p2[t2]=r;
            if(q1[h1]-q2[h2]>=d)
            {
                ans=min(ans,a[r].x-a[l].x);
                break;
            }
        }
    }
    cout<<(ans==inf?-1:ans)<<endl;
    return 0;
}
