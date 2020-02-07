#include<stdio.h>
#include<conio.h>
#include<limits.h>


void printcoins(int n,int s[])
{

	while(s[n]!=0)
	{
		printf("%d cents\n",s[n]);
		n=n-s[n];
	}
}
int dynamic_iterative(int n,int v[],int size)
{
	int i;
	int c[100],s[100];
	c[0]=0,s[0]=0;
	for(i=1;i<=n;i++)
	{
		c[i]=INT_MAX;
		s[i]=-1;
		for(int j=0;j<size;j++)
		{
			if(i>=v[j])
			{
				if(c[i-v[j]]+1<c[i])
				{
					c[i]=c[i-v[j]]+1;
					s[i]=v[j];
				}
			}
		}

	}


	printcoins(n,s);
	return c[n];

}
int main()
{
	int v[100];
	int p,n,m,q;

	printf("how many coins you have?\n");
	scanf("%d",&m);
	printf("enter the coins you have:\n");
	for(q=0;q<m;q++)
	{
		scanf("%d",&v[q]);
	}
	printf("enter how much change you required:\n");
	scanf("%d",&n);
	int val=dynamic_iterative(n,v,m);
	printf(" total %d coins were required!\n",val);

	getch();
	return 0;
}
