/*1
��������
����1200000�ж��ٸ�Լ����ֻ������Լ������
*/
#include<stdio.h>
#define N 1200000
int main()
{
	int n=N,i,num=0;
	for(i=n;i>0;i--)
		if(n%i==0)
			num++;
	printf("%d",num);
}
