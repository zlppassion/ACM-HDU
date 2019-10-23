#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod=1e9+7;
ll a[1005];
ll  s[1005];
int n,m;
void dabiao()
{
    a[1]=1;
    s[1]=1;
    for(int  i=2; i<=n; i++)
    {
        a[i]=((a[i-1]+1)*2)%mod;
        s[i]=(s[i-1]+a[i])%mod;//ÀÛ¼ÆÖµ
    }
}
int main()
{
    scanf("%d%d",&n,&m);

        dabiao();
        int x,y;
        while(m--)
        {
            ll ans=0;
            scanf("%d%d",&x,&y);

            cout<<(s[y]-s[x-1]+mod)%mod<<endl;
        }


    return 0;
}
