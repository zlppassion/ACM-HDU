#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll f(ll x)
{
   ll ans=0;
   while(x)
   {
       ans=ans*10+x%10;
       x/=10;
   }
   return ans;
}
int main()
{
    int T;
    scanf("%d",&T);
    ll a,b;
    while(T--)
    {
        cin>>a>>b;
      //  cout<<f(a)<<endl;
        //cout<<f(b)<<endl;
        cout<<f(f(a)+f(b))<<endl;
    }
}
