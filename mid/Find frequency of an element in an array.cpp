Ques:Find frequency of an element in an array


#include<stdio.h>
#include<conio.h>
int x,count=0;
int frequency(int c[])
{

	for(int i=0;c[i]!='\0';i++)
	{
	if(x==c[i])
		count++;
	}
	return count;
	getch();
}


int main()
{
	int c[100],i,n;
	printf("enter size:");
	scanf("%d",&n);

	printf("enter elements:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&c[i]);
	}
	printf("enter a number to count it's frequency:");
	scanf("%d",&x);
	count=frequency(c);
	printf("frequency of %d is: %d",x,count);
	getch();
	return 0;
}


