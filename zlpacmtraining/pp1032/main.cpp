#include<bits/stdc++.h>
using namespace std;
queue<int> bb;
queue<string> q;
string sa[8],sb[8];//�������ת��
string a,b;//��ʼ�ַ�������ֹ�ַ���
int len;
map<string,int> map1;//��map����Ѿ����ѹ����ַ�������������
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
            //��֦�������ǰ�ַ����Ѿ����ѹ��ˣ��͵�����������һ��ѭ��
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
                m=s.find(sa[i]);//�ҵ��Ӵ�sa[i]�ĵ�һ�γ��ֵ�λ��
                if(m==-1)
                {
                    //���û���ҵ����ͽ���ѭ��
                    break;
                }
                ss=q.front();
                ss.replace(m,sa[i].size(),sb[i]);//��ss�����Ӵ�sb[i]�滻s���һ�γ��ֵ��Ӵ�sa[i]
                q.push(ss);
                bb.push(bb.front()+1);
                s[m]='~';//��s���Ӵ�sa[i]�ĵ�һ�γ���λ����㻻����һ���޹ص��ַ��������Ϳ��Բ��ҵ�s���Ӵ�sa[i]����һ������λ��

            }
        }
        q.pop();//�����������ַ�����������
        bb.pop();//���������ַ����Ѿ��ù��Ĳ���һ�𵯳�


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
    len--;//��Ϊ�����һ�Σ�����һ�κ������ȷ�Ĵ���
    int k=bfs();
    if(k==-1)
    {
        cout<<"NO ANSWER!"<<endl;

    }
    else
        cout<<k<<endl;
    return 0;
}
