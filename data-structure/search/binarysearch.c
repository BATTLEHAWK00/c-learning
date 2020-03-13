#include <stdio.h>
int binarysearch(int *a,int target,int n)
{
	int low=0,mid,high=n;
	while(low<=high)
	{
		mid=(low+high)/2;
		if(a[mid]==target)
			return mid;
		if(a[mid]>target)
			high=mid-1;
		else 
			low=mid+1;
		printf("low=%d high=%d mid=%d\n",low,high,mid);
	}
	return -1;
} 

int main()
{
	int a[50],i;
	for(i=0;i<50;i++)
	{
		a[i]=i+1;
		printf("%d ",i+1);
	}
	printf("\n");
	
	int num,p;
	scanf("%d",&num);
	p = binarysearch(a,num,49);
	printf("%dµÄÎ»ÖÃÊÇ£º%d",num,p);
	return 0;
} 
