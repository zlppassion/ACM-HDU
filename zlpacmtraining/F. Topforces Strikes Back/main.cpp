#include<bits/stdc++.h>
using namespace std;
int main()
{
	int q;
	cin>>q;
	while(q--)
	{
		int n;cin>>n;
		int a[n+4];
		for(int i=0;i<n;++i)
			cin>>a[i];
		sort(a,a+n);
		n=unique(a,a+n)-a;//ȥ�غ��Ԫ�ظ���
		int ans=a[n-1];
		for(int i=0;i<n;++i)
		{
			for(int j=i-1;j>=0;--j)
			{
				if(a[i]%a[j]!=0)//����Ǵ��Ԫ�ص�������ֱ�Ӳ��������
				{
					ans=max(ans,a[i]+a[j]);
					for(int k=j-1;k>=0;--k)
						if(a[i]%a[k]!=0&&a[j]%a[k]!=0)
						{
							ans=max(ans,a[i]+a[j]+a[k]);
							break;//��ʱ�Ѿ��ҵ�������
						}
					break;
				}
			}
		}
		cout<<ans<<endl;

	}
	return 0;
}
