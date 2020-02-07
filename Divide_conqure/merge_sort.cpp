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

void merge(int *A, int left, int mid, int right)
{
    int L[100], R[100];
    int n1=mid-left+1;
    int n2=right-mid;
     L[n1+1]=100000;
     R[n2+1]=100000;
    for(int i=1;i<=n1;++i)
        {
         L[i]=A[left+i-1];
    }
    for(int j=1;j<=n2;++j)
    {
        R[j]=A[mid+j];
    }

    int i=1,j=1;


    for (int k=left;k<=right;k++){
        if (L[i]<=R[j]){
            A[k]=L[i];
            i=i+1;
        }
        else{
            A[k]=R[j];
            j=j+1;
    }

}
}

void merge_sort(int *A, int left, int right)
{
    float mid;
    if (left<right){
        mid=(left+right)/2;

    merge_sort(A,left,mid);
    merge_sort(A,mid+1,right);
    merge(A,left,mid,right);
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

    merge_sort(A, 1, n);

    printf("\nSorted array: ");
    print_array(A, n);

    check_correctness(A, B, n);

    return 0;
}

