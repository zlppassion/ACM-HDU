#include<bits/stdc++.h>
using namespace std;
int const ma = 1e5 + 7;
int mp[507][507], maxn[ma], minn[ma], quema[ma], quemi[ma];
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n, m;
        int ans = 1;
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                scanf("%d", &mp[i][j]);
        for (int i = 1; i <= n; i++)
        {
            for (int p = 1; p <= n; p++)//��ÿһ�ж�Ҫ����
            {
                maxn[p] = 0, minn[p] = ma;
            }
            for (int k = i; k <= n; k++)
            {
                for (int p = 1; p <= n; p++)
                {
                    maxn[p] = max(maxn[p], mp[k][p]);   //���е����
                    minn[p] = min(minn[p], mp[k][p]);
                }
                int f1 = 1, f2 = 1, t1 = 0, t2 = 0, l = 1;//f1,f2���൱�ڶ�ͷ��t1,t2���൱�ڶ�β��
                for (int r = 1; r <= n; r++)//l �� rģ���У�k�� i�Ĳ������
                {
                    while (f1 <= t1 && maxn[quema[t1]] < maxn[r]) t1--;            //ÿ����һ��ֵ��Ե������н�������f1Ϊ��ͷ�����ܳ���
                    while (f2 <= t2 && minn[quemi[t2]] > minn[r]) t2--;
                    quema[++t1] = r;        //�������
                    quemi[++t2] = r;
                    while (l <= r &&((maxn[quema[f1]] - minn[quemi[f2]]) > m))   //f2,f1��λ�þ��Ƕ�Ӧ���е�������Сֵ
                    {
                        l++;
                        if (f1 <= t1 && quema[f1] < l)f1++;             //������ǰѶ�Ӧ��ֵ����ȥ,�ж�λ����������
                        if (f2 <= t2 && quemi[f2] < l)f2++;
                    }
                    ans = max((r - l + 1) * (k - i + 1), ans);  //��*�У�ȥ�����ľ���
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
