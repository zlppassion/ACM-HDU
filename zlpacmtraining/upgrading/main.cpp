#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll sum[1005][1005];
int d[1005];
int a[1005][1005];
int main()
{
    cout<<0ll<<endl;
    int cnt=1,t,n,m;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d",&n,&m);
        for(int i=1; i<=n; i++)
            for(int j=1; j<=m; j++)scanf("%d",&a[i][j]),a[i][j]=-a[i][j];
        for(int i=1; i<=m; i++)scanf("%d",&d[i]);
        /*���⣺��i�����ܣ�ÿ���������л���cij��Ȼ�����м��ܶ��ﵽj����dj��Ǯ�����������׬����

         �⣺�Ƚ����ѳ�-1ת��Ϊ���棬�� a[i][j] ά����׺�ͣ���ʾ j+1~m ������档

        Ȼ��  j ��1 �� m ������j ��ʾ��ǰĳ�����ܵ���͵ȼ����ҵ� �� i ������ ��С�ĺ�׺�ͣ�
        ��ȥ�����׺�Ͳ������������ܵĺ�׺�ͣ��ټ������Լ��ܶ��ﵽ j ������ȡ���ֵ�� */

        for(int i=1; i<=n; i++)
        {
            sum[i][m] = 0;
            for(int j=m-1; j>=0; j--)//Խ��ɱ�Խ��
            {
                sum[i][j] = max(0ll,sum[i][j+1]+a[i][j+1]);
            }
        }
        ll now = 0,ans = 0;
        for(int j=0; j<=m; j++)
        {
            for(int i=1; i<=n; i++)now+=a[i][j];//�������
            now+=d[j];
            ll tp = 0,mi = 1e18;
            for(int i=1; i<=n; i++)
            {
                tp+=sum[i][j];
                mi = min(mi,sum[i][j]);//��С��׺��˵������ǮԽ��
            }

            ans = max(ans,tp-mi+now);
        }
        printf("Case #%d: %lld\n",cnt++,ans);
    }
    return 0;
}
