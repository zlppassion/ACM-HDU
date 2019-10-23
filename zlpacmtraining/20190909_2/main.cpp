#include<bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
#define ll long long
const int N=1005;
const int mod=1e9+7;
const double eps=1e-8;
const double PI = acos(-1.0);
#define lowbit(x) (x&(-x))
int a[N][N],b[2010];
int main()
{
    std::ios::sync_with_stdio(false);
    //freopen("in.txt","r",stdin);
    int n;
    cin>>n;
    int x=0,y=0,z=0;
    for(int i=1; i<=n; i++)
    {
        int k;
        cin>>k;
        int tmp=0;
        for(int j=1; j<=k; j++)
        {
            cin>>a[i][j];
            if(a[i][j]<0)
                tmp+=a[i][j];
            else if(a[i][j]>0)
            {
                if(a[i][j]<tmp)
                    b[i]=1;
                tmp=a[i][j];
            }
        }
        x+=tmp;
     //   cout<<i<<" "<<tmp<<endl;
        if(b[i])
            y++;
    }
    for(int i=1;i<=n;i++)
        b[i+n]=b[i];
    for(int i=1;i<=n;i++)
    {
        if(b[i]+b[i+1]+b[i+2]==3)
            z++;
    }
    cout<<x<<" "<<y<<" "<<z<<endl;
    return 0;
}
/*
5
4 10 0 9 0
4 10 -2 7 0
2 10 0
4 10 -3 5 0
4 10 -1 8 0

4
4 74 -7 -12 -5
5 73 -8 -6 59 -4
5 76 -5 -10 60 -2
5 80 -6 -15 59 0

*/
