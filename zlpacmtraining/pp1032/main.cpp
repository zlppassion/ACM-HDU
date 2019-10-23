#include<bits/stdc++.h>
using namespace std;
queue<int> bb;
queue<string> q;
string sa[8],sb[8];//最多六次转换
string a,b;//起始字符串，终止字符串
int len;
map<string,int> map1;//用map存放已经宽搜过的字符串，用来判重
int bfs()
{
    q.push(a);
    bb.push(0);
    int m;
    string s,ss;
    while(!q.empty()&&bb.front()<10&&q.front()!=b)
    {

        if(map1[q.front()]==1)
        {
            //剪枝，如果当前字符串已经广搜过了，就弹出，进入下一次循环
            q.pop();
            bb.pop();
            continue;
        }
        map1[q.front()]=1;
        for(int i=1; i<=len; i++)
        {
            s=q.front();
            while(1)
            {
                m=s.find(sa[i]);//找到子串sa[i]的第一次出现的位子
                if(m==-1)
                {
                    //如果没有找到，就结束循环
                    break;
                }
                ss=q.front();
                ss.replace(m,sa[i].size(),sb[i]);//在ss中用子串sb[i]替换s里第一次出现的子串sa[i]
                q.push(ss);
                bb.push(bb.front()+1);
                s[m]='~';//将s里子串sa[i]的第一次出现位子随便换成另一种无关的字符，这样就可以查找到s里子串sa[i]的下一个出现位子

            }
        }
        q.pop();//将操作过的字符串弹出队列
        bb.pop();//操作过的字符串已经用过的步数一起弹出


    }
    if(q.empty()==1||bb.front()>10)
        return -1;
    else
        return bb.front();

}
int main()
{
    cin>>a>>b;
    len=1;
    while(cin>>sa[len]>>sb[len])
        len++;
    len--;//因为多加了一次，减掉一次后才是正确的次数
    int k=bfs();
    if(k==-1)
    {
        cout<<"NO ANSWER!"<<endl;

    }
    else
        cout<<k<<endl;
    return 0;
}
