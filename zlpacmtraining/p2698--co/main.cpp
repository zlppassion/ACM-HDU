#include<bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
const int N=1e5+5;
int n;
int q1[N],q2[N],h1,h2,t1,t2,p1[N],p2[N],d;
//q1�����ֵ����
//p1�����ֵ�±����
//q2����Сֵ����
//p2����Сֵ�±����
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
        while(h1<=t1&&p1[h1]<l)//p1�����ֵ�±����
            h1++;
        while(h2<=t2&&p2[h2]<l)//p2����Сֵ�±����
            h2++;
        for(r; r<=n; r++)
        {
            while(h1<=t1&&q1[t1]<=a[r].v)//q1�����ֵ���У�ά�����ֵ����֤���е����ݼ����������С�˾�Ӧ��ɾ��������β��С
                t1--;
            q1[++t1]=a[r].v;
            p1[t1]=r;
            while(h2<=t2&&q2[t2]>=a[r].v)//q2����Сֵ���У�ά����Сֵ����֤���е�����������β���
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
