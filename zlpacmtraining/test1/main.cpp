#include<cstdio>

void print()//�˳�����Ϊ��#Ϊһ���������������
{
	char a;
	scanf("%c",&a);
	if(a!='#')
		print();
	if(a!='#')
		printf("%c",a);
}
int main()
{
	print();
	return 0;

}
