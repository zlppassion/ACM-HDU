#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int a[105];
int main()
{
    int n;
    int ans=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        ans=0;
        scanf("%d",&a[i]);
        for(int j=0;j<i;j++)
        {
            if(a[j]<a[i])
                ans++;
        }
        cout<<ans<<" ";
    }
    cout<<endl;
    return 0;
}
