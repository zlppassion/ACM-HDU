#include <iostream>
#include<bits/stdc++.h>
using namespace std;
#define ll long long
char s[105];
int a[105];
int b[105];
int main()
{
    scanf("%s",s+1);
    int len=strlen(s+1);
    for(int i=1;i<=len;i++)
    {
        a[i]=a[i-1];
        if(s[i]=='Q')
            a[i]++;
    }
    for(int i=len;i>=1;i--)
    {
        b[i]=b[i+1];
        if(s[i]=='Q')
            b[i]++;
    }
    ll ans=0;
    for(int i=2;i<=len-1;i++)
    {
        if(s[i]=='A')
        {
            ans+=(a[i]*b[i]);
        }
    }
    cout<<ans<<endl;
    return 0;
}
