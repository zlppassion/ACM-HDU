#include <bits/stdc++.h>
using namespace std;
int n,r;
stack<int>s;
int main()
{
    char js[]="0123456789ABCDEFGHIJ";//常量数组保存对应基数
    scanf("%d %d",&n,&r);
    printf("%d=",n);//提前输出n，因为后面n变化了，如果想在后面输出，就要多加一个变量保存n
    while(n){
        int a=n%r;
        n/=r;
        if(a<0) {a-=r;n++;}//如果余数为负数，余数减去进制数，商加1
        s.push(a);//结果进栈
    }
    while(!s.empty()){
        printf("%c",js[s.top()]);
        s.pop();
    }
    printf("(base%d)\n",r);
    return 0;
}
