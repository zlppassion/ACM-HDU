#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int a[215];
int n;
ll ans=0;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        a[i+n]=a[i];
    }
    for(int i=1;i<=n;i++)
    {
        ll te=0;
        for(int j=i+1;j<i+n;j++)
        {
            te+=a[i]*a[j]*a[j+1];

        }
         ans=max(ans,te);
    }
    cout<<ans<<endl;
    return 0;
}
