//ע��l���ܴ�0��ʼ�������ǲ����Էֿ��ģ�����û��Ϊ0�����֣�
//����Ҫ����������ʼ����֤����û�в��
#include<cstdio>
#include<algorithm>
using namespace std;
int a[100100],n,m;
bool check(int x)
{
    int sum = 0, cnt = 1;
    for (int i=1; i<=n; ++i)
    {
        sum += a[i];
        if (sum>x)
        {
            cnt++;
            sum = a[i];
            if (cnt>m) return false ;
        }
    }
    return true ;
}
int main()
{
    int l = 0, r = 0, ans;
    scanf("%d%d",&n,&m);
    for (int i=1; i<=n; ++i)
        scanf("%d",&a[i]), r += a[i], l = max(l,a[i]);
    while (l<=r)    //l���ܴ�0��ʼ��
    {
        int mid = (l+r)>>1;
        if (check(mid))//����Ҫ��
        {
            ans = mid;//�����Ը���ֵ
            r = mid-1;//��������Ҫ���Ƿֶκ����ֵ����Сֵ��������r��С
        }
        else l = mid+1;
    }
    printf("%d",ans);
    return 0;
}
