//注意l不能从0开始，数字是不可以分开的，可能没有为0的数字，
//所以要从最大的数开始，保证数字没有拆分
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
    while (l<=r)    //l不能从0开始，
    {
        int mid = (l+r)>>1;
        if (check(mid))//符合要求
        {
            ans = mid;//即可以更新值
            r = mid-1;//但我们需要的是分段和最大值的最小值，所以让r减小
        }
        else l = mid+1;
    }
    printf("%d",ans);
    return 0;
}
