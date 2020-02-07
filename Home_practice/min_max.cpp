#include <cstdio>

 using namespace std;

int large(int[], int, int);

int main()
{
    int size;
    int largest;
    int minest;
    int list[20];
    int i;

    printf("Enter size of the list:");
    scanf("%d", &size);
    printf("Enter the list:\n");
    for (i = 0; i < size ; i++)
    {
        scanf("%d", &list[i]);
    }
    if (size == 0)
    {
        printf("Empty list\n");
    }
    else
    {
        largest = list[0];
        largest = large(list, size - 1, largest);
        printf("\nThe largest number in the list is: %d\n", largest);

        minest = list[0];
        minest= min(list, size - 1, minest);
        printf("\nThe largest number in the list is: %d\n", minest);
    }
}
int large(int list[], int size, int largest)
{
    if (size == 1)
        return largest;

    if (size > -1)
    {
        if (list[size] > largest)
        {
            largest = list[size];
        }
        return(largest = large(list, size - 1, largest));
    }
    else
    {
        return largest;
    }
}

int large(int list[], int size, int minest)
{
    if (size == 1)
        return largest;

    if (size > -1)
    {
        if (list[size] > largest)
        {
            largest = list[size];
        }
        return(largest = large(list, size - 1, largest));
    }
    else

        return largest;
    }
}
