#include<bits/stdc++.h>
using namespace std;
stack<char> s;
int main() {
    char c;
    while(cin>>c&&c!='@') {
        if(c=='(') s.push(c);//入栈
        if(c==')') {
            if(s.empty()) {//如果为空，说明就多了'('了
                printf("NO\n");
                return 0;//至于为啥要判断栈是否为空，大家想想，因为假如有个)，结果前面没有对应(了，那就不行，此时就是栈空
            }
            s.pop();//出栈,匹配了一个就pop一个
        }
    }
    if(s.empty())//判断有没有多余的( ,为空则没有
        printf("YES\n");
    else printf("NO\n");
    return 0;
}
