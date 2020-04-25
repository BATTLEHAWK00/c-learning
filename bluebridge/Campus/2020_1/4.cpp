/*4
问题描述
　　在1至2019中，有多少个数的数位中包含数字9？
　　注意，有的数中的数位中包含多个9，这个数只算一次。例如，1999这个数包含数字9，在计算只是算一个数。
*/
#include<stdio.h>
int main()
{
	int i,num=0;
	for(i=9;i<=2019;i++)
	{
		int n=i,flag=0;
		while(n>0)
		{
			int t=n%10;
			n/=10;
			if(t==9)
				flag=1;
		}
		if(flag)
			num++;
	}
	printf("%d",num);
	return 0;
}
