#include<stdio.h>
int num=17;
void del(int *a,int p)
{
	int i;
	for(i=p;i<num;i++)
		a[i]=a[i+1];
	num--;
}
void printv(int *a)
{
	int i;
	for(i=0;i<num;i++)
		printf("%d ",a[i]);
	printf("\n");
}
int main()
{
	int a[]={11,22,99,33,44,55,55,55,55,55,66,66,77,88,88,99,110};
	int i,j;
	i=0;j=0;
	printf("初始状态：\n");
	printv(a);
	for(i=0;i<num;)
	{
		int flag=0;
		for(j=i+1;j<num;)
		{
			if(a[j]==a[i])
			{
				del(a,j);
				flag=1;
			}else
				j++;
		}
		if(flag)
			del(a,i);
		else 
			i++;
	}
	printf("最后结果：\n");
	printv(a);
 } 
