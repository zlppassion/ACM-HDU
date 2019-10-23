#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int a[105];
int main()
{
    int q,n,k;
    scanf("%d",&q);
    while(q--)
    {
        scanf("%d%d",&n,&k);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        sort(a,a+n);
        if(a[0]+k<a[n-1]-k)
        {
            cout<<"-1"<<endl;

        }
        else
        {
            cout<<a[0]+k<<endl;
        }

    }
    return 0;
}
