#include<cstdio>

void print()//退出条件为：#为一个输入结束的条件
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
