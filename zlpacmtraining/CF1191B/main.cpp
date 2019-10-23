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
    char a[3],b[3],c[3];
    while(cin>>a>>b>>c)
    {
        int x=a[0]-'0',y=b[0]-'0',z=c[0]-'0';
        if(x==y&&y==z&&a[1]==b[1]&&c[1]==c[1])
        {
            cout<<0<<endl;
        }
        else
        {
            set<char> s;
            s.insert(a[1]),s.insert(b[1]),s.insert(c[1]);
            int f=(abs(x-y)<=2||abs(x-z)<=2||abs(y-z)<=2);
            int h[3];
            h[0]=x,h[1]=y,h[2]=z;
            sort(h,h+3);
            if(s.size()==1&&(h[0]+1==h[1]&&h[1]+1==h[2]))
            {
                cout<<0<<endl;
            }
            else if(s.size()==1&&f)
            {
                cout<<1<<endl;
            }
            else if(s.size()==1)
            {
                cout<<2<<endl;
            }
            else if(a[1]==b[1]&&a[1]!=c[1]&&abs(x-y)<=2)
                cout<<1<<endl;
            else if(a[1]==b[1]&&a[1]!=c[1])
                cout<<2<<endl;
            else if(a[1]==c[1]&&a[1]!=b[1]&&abs(x-z)<=2)
                cout<<1<<endl;
            else if(a[1]==c[1]&&a[1]!=b[1])
                cout<<2<<endl;
            else if(b[1]==c[1]&&a[1]!=b[1]&&abs(y-z)<=2)
                cout<<1<<endl;
            else if(b[1]==c[1]&&a[1]!=b[1])
                cout<<2<<endl;
            else if(a[1]!=b[1]&&a[1]!=c[1]&&b[1]!=c[1])
            {
                cout<<2<<endl;
            }
        }
    }
    return 0;
}
