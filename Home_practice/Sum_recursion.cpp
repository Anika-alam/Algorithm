#include<cstdio>

using namespace std;

int sum(int n)
{
    if(n==0)
        return 0;
    else
        return sum(n-1)+n;
}
int main()
{
    int n;
    printf("Enter the number to sum up to: \n", n);
    scanf("%d",&n);
    int summation= sum(n);
    printf("the sum is: %d", summation);
    return 0;
}
