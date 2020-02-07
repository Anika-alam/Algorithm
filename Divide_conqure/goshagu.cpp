#include <cstdio>

using namespace std;

int goshagu(int a, int b)
{
    if(a>=b && a%b==0)
        return b;
    else
        if(a>=b && a%b!=0)
        return goshagu(b,a%b);
    else
        if(b>a && b%a==0)
        return a;
    else
        if(b>a && b%a!=0)
        return goshagu(a,b%a);
}

int main()
{
    int a,b;
    printf("Enter a:\n");
    scanf("%d",&a);
    printf("Enter b:\n");
    scanf("%d",&b);

    int f=goshagu(a,b);
    printf("Goshagu of %d and %d is %d.",a,b,f);

    return 0;
}
