/*8
问题描述
　　小明有一块空地，他将这块空地划分为 n 行 m 列的小块，每行和每列的长度都为 1。
　　小明选了其中的一些小块空地，种上了草，其他小块仍然保持是空地。
　　这些草长得很快，每个月，草都会向外长出一些，如果一个小块种了草，则它将向自己的上、下、左、右四小块空地扩展，这四小块空地都将变为有草的小块。
　　请告诉小明，k 个月后空地上哪些地方有草。
输入格式
　　输入的第一行包含两个整数 n, m。
　　接下来 n 行，每行包含 m 个字母，表示初始的空地状态，字母之间没有空格。如果为小数点，表示为空地，如果字母为 g，表示种了草。
　　接下来包含一个整数 k。
输出格式
　　输出 n 行，每行包含 m 个字母，表示 k 个月后空地的状态。如果为小数点，表示为空地，如果字母为 g，表示长了草。
样例输入
4 5
.g...
.....
..g..
.....
2
样例输出
gggg.
gggg.
ggggg
.ggg.
评测用例规模与约定
　　对于 30% 的评测用例，2 <= n, m <= 20。
　　对于 70% 的评测用例，2 <= n, m <= 100。
　　对于所有评测用例，2 <= n, m <= 1000，1 <= k <= 1000。
*/
#include<stdio.h>
#include<malloc.h>
//char a[1000][1000];
//char last[1000][1000];
int main()
{
	int n,m;
	scanf("%d",&n);
	scanf("%d",&m);
	int i,j,k,mon;
	
	char **a=(char**)malloc(n*sizeof(char*));
	for(i=0;i<n;i++)
		a[i]=(char*)malloc(n*sizeof(char));
	char **last=(char**)malloc(n*sizeof(char*));
	for(i=0;i<n;i++)
		last[i]=(char*)malloc(n*sizeof(char));
	
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
		{
			char p=getchar();
			while(p!='.'&&p!='g')
				p=getchar();
			a[i][j]=p;
			last[i][j]=p;
		}
	scanf("%d",&mon);
	for(k=1;k<=mon;k++)
	{
		for(i=0;i<n;i++)
			for(j=0;j<m;j++)
				if(last[i][j]=='g')
				{
					if(i+1<n)
						a[i+1][j]='g';
					if(i-1>=0)
						a[i-1][j]='g';
					if(j+1<m)
						a[i][j+1]='g';
					if(j-1>=0)
						a[i][j-1]='g';
				}
		for(i=0;i<n;i++)
			for(j=0;j<m;j++)
				last[i][j]=a[i][j];
	}

	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
			putchar(a[i][j]);
		printf("\n");
	}

	return 0;
}
