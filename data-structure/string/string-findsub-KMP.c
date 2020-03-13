#include<stdio.h>
#include<string.h>
#include<malloc.h>
void printp(char *a,int p)
{
	int i;
	puts(a);
	for(i=0;i<p;i++)
		printf(" ");
	printf("|\n");
}
void getnext(char *p,int *next)
{
	next[0]=-1;
	int j=0,k=-1;
	while(j<strlen(p))
	{
		if(k==-1||p[j]==p[k])
		{
			j++;k++;
			next[j]=k;
		}
		else
			k=next[k];
	}
	int m;
	for(m=0;m<strlen(p);m++)
		printf("%d ",next[m]);
	printf("\n");
}
int kmp(char *a,char *b)
{
	int i=0,j=0;
	int *next=(int*)malloc(strlen(b)*sizeof(int));
	getnext(b,next);
	while(i<strlen(a)&&j<strlen(b))
	{
		if(j==-1||a[i]==b[j])
		{
			i++;j++;
			printp(a,i);
		}else
			j=next[j];
	}
	free(next);
	if(j>=strlen(b))
		return i-strlen(b);
	else
		return -1;
}
int main()
{
	char a[]="abasdgdbababababfgabababca",b[]="abababca";
	int p=kmp(a,b);
	puts("原串:");puts(a);
	puts("子串:");puts(b);
	if(p>-1)
		printf("找到起始位置为：%d",p);
	else
		printf("未找到子串");
	return 0;
} 
