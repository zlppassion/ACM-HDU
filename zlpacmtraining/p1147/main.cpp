#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll m,s[2000001];
int check(ll l,ll r,ll k)
{
    if(l>r) return -1;
    ll mid=(l+r)/2;
    if(s[mid]-k==m) return mid;
    else if(s[mid]-k>m) check(l,mid-1,k);
    else if(s[mid]-k<m) check(mid+1,r,k);
}
int main()
{
    cin>>m;
    s[0]=0;
    for(int i=1; i<=2000001; i++)
    {
        s[i]=s[i-1]+i;
    }
    for(int i=1; i<=2000001; i++)
    {
        int k=check(i+1,2000001,s[i-1]);
        if(k!=-1) cout<<i<<" "<<k<<endl;
    }
    return 0;
}
