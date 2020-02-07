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

int parent(int index)
{
	return index/2;
}

// Returns the index of the left child of the node 'index'
int left_child(int index)
{
	return 2*index;
}

// Returns the index of the right child of the node 'index'
int right_child(int index)
{
	return (index*2+1);
}

// Max Heapify at node 'index'
void max_heapify(int *A, int heapSize, int index)
{
	int i,L,R,largest,p;
	L=left_child(index);
	R=right_child(index);
	if((L<=heapSize)&& A[L]>A[index])
	{
		largest=L;
	}
	else
		largest=index;
	if((R<=heapSize)&&(A[R]>A[largest]))
		largest=R;
	if(largest!=index)
	{

		p= A[index];
		A[index] = A[largest];
		A[largest] = p;

		max_heapify(A,heapSize,largest);
	}
}

// Builds the array A into a max heap
void build_max_heap(int *A, int heapSize)
{

	for( int i = heapSize/2; i >= 1; i--)
	{
		max_heapify(A,heapSize,i);
	}
}

// Sorts the array A using the Heapsort algorithm
void heapsort(int *A, int n)
{
    int temp;
	build_max_heap(A,n);
	for (int i = n; i >= 2; i--)
	{

		temp= A[1];
		A[1]= A[i];
		A[i]= temp;

		max_heapify(A,i-1,1);
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
	printf("Enter Size: ");

	scanf("%d", &n);

	generate_random_array(A, n);

	printf("Initial array: ");
	print_array(A, n);

	copy_array(A, B, n);

	heapsort(A, n);

	printf("\nSorted array: ");
	print_array(A, n);

	check_correctness(A, B, n);

	return 0;
}
