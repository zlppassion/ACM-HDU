#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tot, outNum, nowNum = 1;
    queue<int> q;
    cin >> tot >> outNum;                        //��ȡ����
    for (int i = 1; i <= tot; i++)
        q.push(i);    //��ʼ������
    while (!q.empty())                    //�ڶ��в�Ϊ��ʱ����ģ��
    {
        if (nowNum == outNum)
        {
            cout << q.front() << " ";    //��ӡ���ֵ��˵ı��
            q.pop();                    //����
            nowNum = 1;                    //��ʼ�����ڵ�����
        }
        else
        {
            nowNum++;
            q.push(q.front());            //������β
            q.pop();
        }
    }
    cout << endl;
    return 0;
}
