/*5��������
����С���������� hello ���ֵ��ʷǳ�����Ȥ�����ֵ��ʿ������÷�Ϊ�ĶΣ���һ����һ������������ĸ��ɣ��ڶ�����һ������Ԫ����ĸ��ɣ���������һ������������ĸ��ɣ����Ķ���һ������Ԫ����ĸ��ɡ�
��������һ�����ʣ����ж���������Ƿ�Ҳ�����ֵ��ʣ�����������yes�����������no��
����Ԫ����ĸ���� a, e, i, o, u���������������Ϊ������ĸ��
�����ʽ
��������һ�У�����һ�����ʣ�������ֻ����СдӢ����ĸ��
�����ʽ
��������𰸣�����Ϊyes������Ϊno��
��������
lanqiao
�������
yes
��������
world
�������
no
����������ģ��Լ��
���������������������������е���ĸ����������100��
*/
#include<stdio.h>
int yy(char p)
{
	switch(p)
	{
		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u':return 1;
		default:return 0;
	}
}
int main()
{
	char word[100],*p=word;
	gets(word);
	int num=0;
	while(*p!='\0')
	{
		switch(num)
		{
			case 0:if(!yy(*p)) num++; break;
			case 1:if(yy(*p)) num++;break;
			case 2:if(!yy(*p)) num++;break;
			case 3:if(yy(*p)) num++;break;
			case 4:if(!yy(*p)) num++;break;
		}
		//printf("p=%c num=%d\n",*p,num);
		p++;
	}
	if(num==4)
		printf("yes");
	else
		printf("no");
	return 0;
}
