#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=200000+10;
const int INF = 0x3f3f3f3f;
ll ans;
int a[N],t,n,m;
int main()
{
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        ans=0;
        for(int i=1;i<=n;i++)a[i]=0;
        for(int i=1;i<=n;i++)scanf("%d",&m),a[m]++;
        sort(a+1,a+n+1);
        int now=INF;
        for(int i=n;i>=1&&a[i]&&now;i--){//�Ӵ�С����

            if(now<=a[i])now--;//�������õĺ������������ˣ������ж�����ֶ��Ǹ�������
            else now=a[i];
            ans+=now;
        }
        cout<<ans<<endl;
    }
    return 0;
}
