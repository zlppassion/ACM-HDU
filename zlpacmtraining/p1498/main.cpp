#include<iostream>
using namespace std;
const int maxn=3005;
char a[maxn][maxn];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin>>n;
    for(int i=0; i<maxn; i++)
        for(int j=0; j<maxn; j++)
            a[i][j]=' '; //��ȫ����Ϊ�ո�,����մ������鷳Ҫif����ո�

    //1.�����ͼ��(n=1���ŵ�)
    a[0][0]='/';
    a[0][1]='_';
    a[0][2]='_';
    a[0][3]='\\';
    a[1][1]='/';
    a[1][2]='\\';

    //2.�����ұߺ��ϱ�
    int len=4,k=1;//len��ʾ��ǰͼ�ڵĿ�,len/2��ͼ�ڵĸ�;�ܹ۲쵫�������Ĺ���:��͸߶�ô��Ҫ!
    while(k<n)//���ϸ���
    {
        for(int i=0; i<len/2; i++)
        {

            for(int j=0; j<len; j++)
            {
                a[i][j+len]=a[i][j];//�ұ�ֻ�ӿ�
                a[i+len/2][j+len/2]=a[i][j];//�ϱ߼Ӹ߼ӿ�
            }
        }

        len*=2;
        k++;
    }
    //3.���
    for(int i=(len/2)-1; i>=0; i--) //�������
    {
        for(int j=0; j<len; j++)
        {
            cout<<a[i][j];
        }
        cout<<endl;
    }

    return;
}
