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
        //较小的元素，存入temp临时数组中
        if(a[i]<=a[j])
            b[k++]=a[i++];
        else//出现逆序对
        {
            b[k++]=a[j++];
            countt+=mid-i+1;
        }
    }
    //假如第1个有序区仍有剩余，则直接全部复制到 b数组
    while(i<=mid)
        b[k++]=a[i++];
    //同理，有剩余则放到 b数组
    while(j<=R)
        b[k++]=a[j++];
    //将排好的序列，重新放到原数组的 L和 R区间
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
