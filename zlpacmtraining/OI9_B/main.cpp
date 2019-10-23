#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int a[100005];
int main()
{
     int n;
     scanf("%d",&n);
     int ans=0;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
         if(a[i]<0)
            a[i]=-a[i];
    }
     for(int i=0;i<n;i++)
     {
         int num1=0;
         int num0=0;
        while(a[i])
        {
            if(a[i]&1)
            {
                num1++;
            }
            else
                num0++;
            a[i]/=2;
        }
        //cout<<a[i]<<" "<<num1<<" "<<num0<<endl;
        if(num1>num0)
        {
            ans+=1;
        }
        else
            ans-=1;

     }


     printf("%d\n",ans);
    return 0;
}
