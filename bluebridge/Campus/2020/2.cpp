/*1
问题描述
　　1200000有多少个约数（只计算正约数）。
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
