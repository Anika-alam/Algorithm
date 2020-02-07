#include<cstdio>

using namespace std;

int factorial(int n)
{
    if(n==0)
        return 1;
    else
        return factorial(n-1)*n;
}

int main()
{
    int n;
    printf("enter the number to find factorial:\n");
    scanf("%d",&n);
    int f=factorial(n);
    printf("the factorial is: %d", f);
}
