#include<bits/stdc++.h>
using namespace std;
stack<char> s;
int main() {
    char c;
    while(cin>>c&&c!='@') {
        if(c=='(') s.push(c);//��ջ
        if(c==')') {
            if(s.empty()) {//���Ϊ�գ�˵���Ͷ���'('��
                printf("NO\n");
                return 0;//����ΪɶҪ�ж�ջ�Ƿ�Ϊ�գ�������룬��Ϊ�����и�)�����ǰ��û�ж�Ӧ(�ˣ��ǾͲ��У���ʱ����ջ��
            }
            s.pop();//��ջ,ƥ����һ����popһ��
        }
    }
    if(s.empty())//�ж���û�ж����( ,Ϊ����û��
        printf("YES\n");
    else printf("NO\n");
    return 0;
}
