#include <cstdio>


int lcm(int a, int b)
{
    static int c = 1;

    if (c % a == 0 && c % b == 0)
    {
        return c;
    }
    c++;
    lcm(a, b);
    return c;
}

int main()
{
    int a, b, result;

    printf("Enter two numbers: ");
    scanf("%d%d", &a, &b);
    result = lcm(a, b);
    printf("The LCM of %d and %d is %d\n", a, b, result);
    return 0;
}
