#include <bits/stdc++.h>
using namespace std;
int n,r;
stack<int>s;
int main()
{
    char js[]="0123456789ABCDEFGHIJ";//�������鱣���Ӧ����
    scanf("%d %d",&n,&r);
    printf("%d=",n);//��ǰ���n����Ϊ����n�仯�ˣ�������ں����������Ҫ���һ����������n
    while(n){
        int a=n%r;
        n/=r;
        if(a<0) {a-=r;n++;}//�������Ϊ������������ȥ���������̼�1
        s.push(a);//�����ջ
    }
    while(!s.empty()){
        printf("%c",js[s.top()]);
        s.pop();
    }
    printf("(base%d)\n",r);
    return 0;
}