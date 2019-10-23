#include <iostream>
#include<bits/stdc++.h>
using namespace std;

long long a[105];
int main()
{
    int i=0;
    for( i=0;;i++)
    {
        scanf("%lld",&a[i]);
        if(a[i]==0)
        {
            break;
        }
    }
    int t=i-1;
    for(;t>0;t--)
    {
        cout<<a[t]<<" ";
    }
    cout<<a[0]<<endl;
    return 0;
}
