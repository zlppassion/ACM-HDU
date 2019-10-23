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
    //�õ���ջ���в��� R[i]��ʾ�ұ߽� L[i]��ʾ��߽�,��¼��a����ÿ��������Ϊ��Сֵ��������������ĸ��㣬���ұ����ĸ���
    for(int i=1; i<=n; i++)
    {
        while(!st.empty()&&a[i]<=a[st.top()])
        {
            st.pop();
        }
        if(st.empty()) L[i]=1;//��һ�������������ߵ�Ȼ��������
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
        if(a[i]>=0)//��Ȼa[i]Ϊ�Ǹ�������ôb���������Խ��Խ�ã������ұ߽��ȥ��߽�Ϊ���
        {
            ans=max(ans,a[i]*(s[R[i]]-s[L[i]-1]));
        }
        else//���Ϊ�������������������С�� ��ôҪ��i֮ǰ��ǰ׺������λ�ã�
        {
            ll mxx, mii; //��i֮����ǰ׺����С��λ�ã���С�����Ϊ����
			mxx =queryMax(L[i], i, 1, n, 1);
			if(mxx < 0) {
				mxx = 0; //ǰ������ �����ֵ��� С��0��ȥֱ����iΪ��߽�
			}
            //ll mxx=queryMax(max(1,L[i]-1),max(i-1,L[i]),1,n,1);
             mii=queryMin(i,R[i],1,n,1);
            ans=max(ans,(mii-mxx)*a[i]);
        }
    }
    printf("%lld\n",ans);
    return 0;
}
