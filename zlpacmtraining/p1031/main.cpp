#include<iostream>
#include<cstdio>
using namespace std;
/*��������˵��ƽ������Ϊ10��ԭ������Ϊ-1��-2,+7��-4����Ϊû��Ϊ0���������Դ�����߳�������-1�ƶ���-2�У�
��Ϊ0��-3��+7,4���ٽ�-3�����ƶ�����һ�����ƣ�ֱ��ȫΪ0Ϊֹ��
ÿ�ƶ�һ�Σ��������1���ؼ��ǣ�������ô�ƶ�����ʵ���ƶ�-x���ƣ���ʵ���Ǵ���һ�����ƶ�x���ƣ�������ͬ��*/
int a[105];
int main()
{
    int n;
    int sum=0,x=0,ans=0;
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
        sum+=a[i];
    }
    x=sum/n;
    for(int i=1; i<=n; i++)
        a[i]-=x;
    for(int i=1; i<=n; i++)
    {
        if(a[i]==0) continue;
        a[i+1]+=a[i];
        ans++;
    }
    cout<<ans<<endl;
    return 0;
}
