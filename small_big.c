#include<stdio.h>
#include<stdlib.h>


int main(int argv, char *argc[])
{
	int a[10] = {2,5,4,1,8,9,11,6,3,7};
	int small,big;
	small= big = a[0];
	for(int i =0;i<10;i++)
	{
		if(small>a[i])
			small = a[i];
		else if (big < a[i])
			big = a[i];
	} 
	printf("small=%d,big=%d\n",small,big);
return 0;
}
