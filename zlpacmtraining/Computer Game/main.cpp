#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int k,n,a,b,ans;
bool check(ll x)
{
    if(x>n)
        return 0;//��Ϊ����Ҫ���������Ϸ�����պô���nʱ�����������
    ll te=k-x*a-(n-x)*b;
    return te>0;//��������Ϸ��������ʱ����ʣ������
}
int main()
{
    int q;
    scanf("%d",&q);

    while(q--)
    {
        scanf("%d%d%d%d",&k,&n,&a,&b);
        ans=-1;
        ll l=0,r=1e9;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(check(mid))
            {
                ans=mid;
                l=mid+1;//�������Ҫ��ÿ���ⲻһ��������������𰸻����Ը�����Ϊ���������ֵ
            }
            else
                r=mid-1;
        }
        cout<<ans<<endl;
    }
    return 0;
}
