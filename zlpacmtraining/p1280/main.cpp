#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll maxn=10010;
ll n,k,q=1;
ll b[maxn],ans[maxn];
struct node
{
    ll p,t;
} a[maxn]; //�ýṹ�����򷽱�

bool cmp(node a,node b)
{
    return a.p>b.p;    //�����ƣ����ԴӴ�С
}
int main()//��ʼ��
{

    scanf("%lld %lld",&n,&k);
    for(ll i=1; i<=k; i++)
    {
        scanf("%lld %lld",&a[i].p,&a[i].t);
        b[a[i].p]++;//b����������a[i].p�Ŀ�ʼʱ���������
    }
    sort(a+1,a+k+1,cmp);//����
    for(ll i=n; i>0; i--) //ע��������{
        if(b[i]==0)//˵����ʱ��û���������Կ���ʱ��Ϊ�̳���һʱ�̵Ŀ���ʱ��+1
            ans[i]=ans[i+1]+1;
        else//��ʱ��������
        {
            for(ll j=1; j<=b[i]; j++)//ע��b[i]����iʱ�俪ʼ���������������������
            {
                if(ans[i+a[q].t]>ans[i])//����������ʱ��,i+a[q].t��ľ��ǽ���ʱ��
                    ans[i]=ans[i+a[q].t];
                q++;
            }
        }

//�ⷽ��
    printf("%lld",ans[1]);//������ڵ�һλ�����
    return 0;
}
