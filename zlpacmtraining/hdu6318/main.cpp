#include <bits/stdc++.h>
using namespace std;
#define ll long long
long long a[1000005];
long long b[1000005];
long long countt;
void Merge(long long *a,ll L,ll mid,ll R)
{
    ll k=L;
  ll i=L,j=mid+1;
    while(i<=mid && j<=R)
    {
        //��С��Ԫ�أ�����temp��ʱ������
        if(a[i]<=a[j])
            b[k++]=a[i++];
        else//���������
        {
            b[k++]=a[j++];
            countt+=mid-i+1;
        }
    }
    //�����1������������ʣ�࣬��ֱ��ȫ�����Ƶ� b����
    while(i<=mid)
        b[k++]=a[i++];
    //ͬ����ʣ����ŵ� b����
    while(j<=R)
        b[k++]=a[j++];
    //���źõ����У����·ŵ�ԭ����� L�� R����
    for(ll t=L; t<=R; t++)
        a[t]=b[t];
}
void MergeSort(long long *a,ll L,ll R)
{
    if(L<R)
    {
        ll mid = (L+R)/2;
        MergeSort(a,L,mid);
        MergeSort(a,mid+1,R);
        Merge(a,L,mid,R);
    }
}
int main()
{
    ll n,x,y,i;
    while(scanf("%lld%lld%lld",&n,&x,&y))
    {
        for(i=0; i<n; i++)
            scanf("%lld",&a[i]);
        countt=0;
        MergeSort(a,0,n-1);
        printf("%lld\n",countt*min(x,y));
    }
    return 0;
}
