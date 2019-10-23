#include<bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
#define ll long long
const int N=3e6+5;
const int mod=1e9+7;
const double eps=1e-8;
const double PI = acos(-1.0);
#define lowbit(x) (x&(-x))
ll a[N],b[N];
ll mi[N<<2],mx[N<<2],s[N];
void pushUp(int rt)
{
    mi[rt]=min(mi[rt<<1],mi[rt<<1|1]);
    mx[rt]=max(mx[rt<<1],mx[rt<<1|1]);
}
void build(int l,int r,int rt)
{
    if(l==r)
    {
        mi[rt]=mx[rt]=s[l];
        return;
    }
    int m=(l+r)>>1;
    build(l,m,rt<<1);
    build(m+1,r,rt<<1|1);
    pushUp(rt);
}
ll queryMin(int L,int R,int l,int r,int rt)
{
    if(L <= l && r <= R)
    {
        return mi[rt];
    }
    int m=(l+r)>>1;
    ll ans=1e14;
    if(L <= m) ans=min(ans,queryMin(L,R,l,m,rt<<1));
    if(R >  m) ans=min(ans,queryMin(L,R,m+1,r,rt<<1|1));
    return ans;
}
ll queryMax(int L,int R,int l,int r,int rt)
{
    if(L <= l && r <= R)
    {
        return mx[rt];
    }
    int m=(l+r)>>1;
    ll ans=-1e14;
    if(L <= m) ans=max(ans,queryMax(L,R,l,m,rt<<1));
    if(R >  m) ans=max(ans,queryMax(L,R,m+1,r,rt<<1|1));
    return ans;
}
int L[N],R[N];
int main()
{
    std::ios::sync_with_stdio(false);
    int n;
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
        scanf("%lld",&a[i]);
    for(int i=1; i<=n; i++)
        scanf("%lld",&b[i]),s[i]=s[i-1]+b[i];
    build(1,n,1);
    stack<int> st;
    //用单调栈进行操作 R[i]表示右边界 L[i]表示左边界,记录下a数组每个点以他为最小值的区间最左边是哪个点，最右边是哪个点
    for(int i=1; i<=n; i++)
    {
        while(!st.empty()&&a[i]<=a[st.top()])
        {
            st.pop();
        }
        if(st.empty()) L[i]=1;//第一个点的区间最左边当然是它本身
        else L[i]=st.top()+1;
        st.push(i);
    }
    while(!st.empty()) st.pop();
    for(int i=n; i>=1; i--)
    {
        while(!st.empty()&&a[i]<=a[st.top()])
            st.pop();
        if(st.empty()) R[i]=n;
        else R[i]=st.top()-1;
        st.push(i);
    }
    ll ans=0;
    for(int i=1; i<=n; i++)
    {
        if(a[i]>=0)//既然a[i]为非负数，那么b数组区间和越大越好，所以右边界减去左边界为最佳
        {
            ans=max(ans,a[i]*(s[R[i]]-s[L[i]-1]));
        }
        else//如果为负数，尽量找区间和最小， 那么要在i之前找前缀和最大的位置，
        {
            ll mxx, mii; //在i之后找前缀和最小的位置，最小减最大极为最优
			mxx =queryMax(L[i], i, 1, n, 1);
			if(mxx < 0) {
				mxx = 0; //前面区间 的最大值如果 小于0则不去直接以i为左边界
			}
            //ll mxx=queryMax(max(1,L[i]-1),max(i-1,L[i]),1,n,1);
             mii=queryMin(i,R[i],1,n,1);
            ans=max(ans,(mii-mxx)*a[i]);
        }
    }
    printf("%lld\n",ans);
    return 0;
}
