#include<stdio.h>
#include<string.h>
int findsub(char *a,char *b)
{
	int p,i,j;
	for(p=0;p<strlen(a)-strlen(b)+1;)
	{
		for(i=p,j=0;a[i]==b[j]&&j<strlen(b);i++,j++);
		if(j==strlen(b))
			return p;
		else
			p++;
	}
	return -1;
}
int main()
{
	char a[]="abcdefg",b[]="efg";
	int p=findsub(a,b);
	puts("ԭ��:");puts(a);
	puts("�Ӵ�:");puts(b);
	if(p>-1)
		printf("�ҵ���ʼλ��Ϊ��%d",p);
	else
		printf("δ�ҵ��Ӵ�");
	return 0; 
}
