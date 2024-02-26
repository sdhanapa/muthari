#include<stdio.h>
#include<stdlib.h>

void func(int ar[]);
int main(int argv, char *argc[])
{
	int a[6] = {1,2,3,4,5,6};
	int j =0;
	func(a);
	for(j=0;j<6;j++)
	{
		printf("%d ",a[j]);
	}
	printf("\n");
return 0;
}
void func(int ar[])
{
int sum=0;

	for(int i = 0;i<6;i++)
	{
		ar[i] = ar[i] * ar[i];
		sum += ar[i];
	}
	printf("sum = %d\n",sum);
}
