#include<bits/stdc++.h>
using namespace std;
const int maxn=2e6+5;
struct node{
    int num,pos;
}e[maxn];
bool cmp(node a,node b)//����
{
    if(a.num==b.num)
        return a.pos>b.pos;//���ǰ׺����ȣ�����λ�ôӴ�С��
    return a.num<b.num;//ǰ׺�ʹ�С��������
}
/*��һ��ǰ׺��num����Ҫ������num[x]-num[y]>0������(x-y)����ô���Ǵ�С�����Ÿ���
������ɨһ�飬��¼num����С��position��ÿ���õ�ǰ��position��ȥ��С��position������һ�½����
�����ʱ��Ҫ����һ��num[0]�����������κ�һ������num[0]��ֵΪ0��;
*/
int main()
{
    int n,x;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&x);
        e[i].num=x+e[i-1].num;//ǰ׺��
        e[i].pos=i;//λ��
    }
    n++;
    sort(e+1,e+n+1,cmp);
    int minx=n;
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        minx=min(minx,e[i].pos);
        if(e[i].pos>minx)
            ans=max(ans,e[i].pos-minx);
    }
    printf("%d\n",ans);
    return 0;
}
