#include<stdio.h>
#define N 1200000
/* 1��������
����1200000�ж��ٸ�Լ����ֻ������Լ������
*/
int main()
{
	int n=N,i,num=0;
	for(i=n-1;i>0;i--)
		if(n%i==0)
			num++;
	printf("%d",num);
}
