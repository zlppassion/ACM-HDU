#include<bits/stdc++.h>
using namespace std;
int n;
void digui(int x)
{
    if(x==0)
        return;
    int y;
    for(int i=0;i<=15;i++)//��Ϊ���ݷ�ΧΪ20000,2^14=16384,2^15=32768
    {
        y=i;
        if(pow(2,i)>x)
        {
            //�����һ�δ�����,����Ӧ��y--
            y--;//���Դ�Ϊ2^y��2^y+����
            break;
        }
    }
    if(y==0)
        cout<<"2(0)";
    else if(y==1)
        cout<<"2";
    else if(y>1)
    {
        cout<<"2(";
        digui(y);
        cout<<")";
    }
    if(x!=pow(2,y))
    {
        cout<<"+";
        digui(x-pow(2,y));
    }
}
int main()
{
    scanf("%d",&n);
   digui(n);
    return 0;
}
