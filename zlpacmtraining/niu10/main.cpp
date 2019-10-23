#include<bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
#define ll long long
const int N=200005;
const int mod=1e9+7;
const double eps=1e-8;
const double PI = acos(-1.0);
#define lowbit(x) (x&(-x))
int main()
{
    std::ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)
    {
        int a,b,g[10][10];
        int du[10],cnt[10];
        memset(du,0,sizeof(du));
        memset(cnt,0,sizeof(cnt));
        memset(g,0,sizeof(g));
        for(int i=1; i<=5; i++)
        {
            cin>>a>>b;
            g[a][b]=g[b][a]=1;
            du[a]++,du[b]++;
        }
        for(int i=1; i<=6; i++)
            cnt[du[i]]++;
        if(cnt[2]==4&&cnt[1]==2)
        {
            cout<<"n-hexane"<<endl;
        }
        else if(cnt[3]==1&&cnt[2]==2&&cnt[1]==3)
        {
            int f=0,k;
            for(int i=1; i<=6; i++)
            {
                if(du[i]==3)
                {
                    k=i;
                    break;
                }
            }
            int r[3],tot=0,x=0;
            for(int i=1; i<=6; i++)
            {
                if(k!=i&&g[k][i])
                    r[tot++]=i;
            }
            for(int i=0; i<3; i++)
                if(du[r[i]]==1)
                    x++;
            if(x==1)
                cout<<"3-methylpentane"<<endl;
            else
                cout<<"2-methylpentane"<<endl;
        }
        else if(cnt[3]==2&&cnt[1]==4)

        {
            cout<<"2,3-dimethylbutane"<<endl;
        }
        else if(cnt[4]==1&&cnt[2]==1&&cnt[1]==4)
        {
            cout<<"2,2-dimethylbutane"<<endl;
        }
    }
    return 0;
}
