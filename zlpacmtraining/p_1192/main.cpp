#include <iostream>
#include<bits/stdc++.h>
using namespace std;
const int mod=100003;
int s[100005];
int n,k;//���n�㣬���һ��k�����󷽰���
//�����Լ�ģ��һ�£����Է���ÿһ����ĵ��ƹ�ϵΪs[n]=��ͣ�s[n-k]~s[n-1])
//�Ϳ�������Ϊ���һ����Խ1~k��̨�׵�������������
int main()
{
    scanf("%d%d",&n,&k);
    s[0]=1;//��ʼ����һ�����
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=k&&(i-j)>=0;j++)
        {
            s[i]=(s[i]+s[i-j])%mod;
        }
    }
    cout<<s[n]<<endl;
    return 0;
}
