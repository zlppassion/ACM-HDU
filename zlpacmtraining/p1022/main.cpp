#include <iostream>
#include <cstdio>
using namespace std;
char c,a;//c��������,a��δ֪����
int f=1,now=1,k,b,x;//f��ʼ��Ϊ����now��ʼΪ��k��b��x��������
bool r;//�������Ƿ������ֶ���
int main()
{
    while(cin>>c)//���ִ��������Ѿ����͵ĺ�����ˡ������ɣ�
    {
        if(c=='-') {b+=now*f*x;x=0;f=-1;r=0;}
        if(c=='+') {b+=now*f*x;x=0;f=1;r=0;}
        if(c=='=') {b+=now*f*x;x=0;f=1;now=-1;r=0;}
        if(c>='a'&&c<='z')
        {
            if(r)
            {
                k+=now*f*x;x=0;
            }
            else k+=now*f;
            a=c;r=0;
        }
        if(c>='0'&&c<='9') {x=x*10+c-'0';r=1;}
    }
    b+=now*f*x;//�������һ����������һ����δ֪������0��
    double ans=double(-b*1.0/k);
    if(ans==-0.0) ans=0;//���У���-0.0��Ϊ0
    printf("%c=%.3lf",a,ans);//������λС�����
    return 0;
}
