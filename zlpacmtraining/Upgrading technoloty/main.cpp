#include<bits/stdc++.h>
#define MAXN 45689
#define INF 0x3f3f3f3f//����ll�����������һ�룬���ҳ�2���ᱬll
const ll mod = 1000000007;

ll a[1005][1005];
ll zui[1005][1005];
int main()
{
    int t, n, m, ccc=1;
    cin >> t;
    while(t--)
    {
        memset(a, 0, sizeof(a));
        memset(zui, 0, sizeof(zui));
        scanf("%d %d", &n, &m);
        for(int i=1; i<=n; ++i)
        {
            for(int j=1; j<=m; ++j)
            {
                scanf("%lld", &a[i][j]);
                a[i][j] += a[i][j-1];
            }
            zui[i][m] = a[i][m];
            for(int j=m-1; j>=0; --j)    //��ÿһ�к�׺�ͣ��������
                zui[i][j] = min(zui[i][j+1], a[i][j]);
        }

        ll sum=0, ans=0;
        for(int j=0, c; j<=m; ++j)//��0��ʼѭ������Ϊ��һ�в�һ��ȫ��ѡ����
        {
            ll mn=0, mx=0;
            for(int i=1; i<=n; ++i)
            {
                mn+=a[i][j];        //�����
                mx+=zui[i][j];
            }
            for(int i=1; i<=n; ++i)//�ж���ȫ��ѡ���أ�����ֻѡ�񲿷�
                mn = min(mn, mx - zui[i][j] + a[i][j]);//��Ϊmx��zui[i][j]�ۼӵģ���������൱���жϲ����������������

            sum = max(sum, ans - mn);   //ά����ʧ��ֵ
            if(j < m)
            {
                scanf("%d", &c);        //�õ�dj
                ans+=c;
            }
        }
        printf("Case #%d: %lld\n", ccc++, sum);
    }
    return 0;
}
