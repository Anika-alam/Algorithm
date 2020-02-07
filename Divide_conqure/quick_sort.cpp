#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<algorithm>

using namespace std;

#define SIZE 102

void generate_random_array(int *A, int n)
{
    srand(time(NULL));

    for(int i = 1; i <= n; ++i)
        A[i] = rand() % 100;
}

void print_array(int *A, int n)
{
    for(int i = 1; i <= n; ++i)
        printf("%d ", A[i]);

    printf("\n");
}

void copy_array(int *source, int *target, int n)
{
    for(int i = 1; i <= n; ++i)
        target[i] = source[i];
}



void quick_sort(int list[], int low, int high)
{
    int pivot, i, j, temp;
    if (low < high)
    {
        pivot = low;
        i = low;
        j = high;
        while (i < j)
        {
            while (list[i] <= list[pivot] && i <= high)
            {
                i++;
            }
            while (list[j] > list[pivot] && j >= low)
            {
                j--;
            }
            if (i < j)
            {
                temp = list[i];
                list[i] = list[j];
                list[j] = temp;
            }
        }
        temp = list[j];
        list[j] = list[pivot];
        list[pivot] = temp;
        quick_sort(list, low, j - 1);
        quick_sort(list, j + 1, high);
    }
}

void check_correctness(int *A, int *B, int n)
{
    int i;

    sort(B + 1, B + 1 + n);

    for(i = 1; i <= n; ++i)
        if(A[i] != B[i])
            break;

    printf("\n%s Sorting\n", i <= n ? "Incorrect" : "Correct");
}

int main()
{
    int n, A[SIZE], B[SIZE];
    printf("Enter how many numbers:\n");

    scanf("%d", &n);

    generate_random_array(A, n);

    printf("Initial array: ");
    print_array(A, n);

    copy_array(A, B, n);

    quick_sort(A, 1, n);

    printf("\nSorted array: ");
    print_array(A, n);

    check_correctness(A, B, n);

    return 0;
}
