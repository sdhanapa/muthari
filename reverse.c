#include<stdio.h>


int main(int argv, char *argc[])
{
	int a[10] = {1,2,3,4,5,6,7,8,9,10};
	int tmp;
	int i =0,k=0;
	printf("Before reversig...!\n");
	for( k =0;k<10;k++)	
	{
		printf("%d ",a[k]);
	}	
	printf("\n");
	for(int j =9;j>=5;j--)
	{
	  tmp = a[i];
	  a[i]=a[j];
	  a[j] = tmp;
	  i++;
	}
	printf("After reversig...!\n");	
	for( k =0;k<10;k++)	
	{
		printf("%d ",a[k]);
	}
	printf("\n");	
return 0;
}
