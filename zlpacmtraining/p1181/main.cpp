#include <iostream>
#include<bits/stdc++.h>
using namespace std;
const int maxn=100005;
int a[maxn];
#define ll long long
int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    long long ans=0;
    ll pre=0;//代表前面加起来的值
    for(int i=0;i<n;i++)
    {
        if(pre+a[i]>m)
        {
            pre=a[i];
            ans++;
        }
        else
            pre+=a[i];
    }
    if(pre>0)
        ans++;
   /* for(int i=0;i<n-1;i++)
    {
        if(a[i]+a[i+1]>m)
            ans++;
        else
        {
            i++;
            ans++;
        }

    }*/
    cout<<ans<<endl;
    return 0;
}
