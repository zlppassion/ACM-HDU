/*�ٸ����ӣ�����01101111�����������ĿҪ������õĴ�
��ֻ��01101111���������Լ�����⣬�ͻ���011��01111��
���������Ĳ�֮ͬ����
���Ծ�ֻ�ܰ���󳤶ȵ���С��ʾ���ķ��������ϴ��룺*/
#include <bits/stdc++.h>
using namespace std;
const int maxn=2001;
int t;
string str;
bool judge(string s)
{
    int i=0,j=1,k=0,ll=s.length();
    while (i<ll && j<ll && k<ll)
    {
        int com=s[(i+k)%ll]-s[(j+k)%ll];
        if(com==0)//��λ��ȵ����
            k++;
        else
        {
            if(com>0)//���Ϊi���ֻ��ַ����Ƚϴ��ʱ��
                i+=(k+1);
            else
                j+=(k+1);//���Ϊj���ֻ��ַ����Ƚϴ��ʱ��
            if(i==j)
                j++;//������ȵ����
            k=0;
        }
    }
    if(min(i,j)==0)
        return 1;
    else
        return 0;
}//����Ƿ�Ϊ��С��ʾ
int main()
{
    scanf("%d",&t);
    while (t--)
    {
        cin>>str;
        int len=str.length();
        int l=0;
        while(1)
        {
            for(int i=len; i>=0; i--) //ö�ٵ�i-l�ĳ��ȣ��Ӵ�Ŀ�ʼö�٣���ΪҪ������ٲ���,(i-l)������ʣ�µĳ���
            {
                string s=str.substr(l,i-l);//ȡ�Ӵ��ķ�ʽ��ǰ��ʱ��ʼλ�ã�����ʱ��ȡ����
                if(judge(s))
                {
                    cout<<s;
                    l=i;
                    break;
                }
            }
            if(l!=len)
                cout<<' ';
            else
                break;
        }
        cout<<endl;
    }
    return 0;
}
