#include <iostream>
#include<bits/stdc++.h>
using namespace std;
char a[100005];
int s[100005];
int N;
bool check(int mid)//mid即代表长度
{
    for(int i=1;i+mid-1<=N;i++)
    {
        if(s[i+mid-1]-s[i-1]==mid/2)
            return true;
    }
    return false;
}
int main()
{

    scanf("%d",&N);
    cin>>a+1;
    for(int i=1;i<=N;i++)
    {
        s[i]=s[i-1]+a[i]-'0';
    }
    int l=0,r=1e9,ans=0;
    cout<<r<<endl;
    while(l<=r)
    {
        int mid=(r+l)/2;
        if(mid%2)
            mid+=1;
        if(check(mid))
        {
            ans=mid;
            l=mid+2;
        }
        else
            r=mid-2;
    }
    cout<<ans<<" "<<min(s[N],N-s[N])*2<<endl;
    return 0;
}
