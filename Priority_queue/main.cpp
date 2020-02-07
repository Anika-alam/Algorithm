#include<cstdio>
#include<stdio.h>
#include<iostream>

using namespace std;

#define SIZE 102
int heapSize=0;
// Returns the index of the parent of the node 'index'
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
    int L,R,largest,p;
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

void print_array(int *A, int n)
{
    for(int i = 1; i <= n; ++i)
        printf("%d ", A[i]);

    printf("\n");
}



// Returns the maximum element of the priority queue A
int heap_maximum(int *A)
{
    if(heapSize == 0)
    {
        printf("The heap is empty.");
        return -1;
    }
    return A[1];
}

// Returns the maximum element of the max priority queue A; also deletes it from A
int heap_extract_max(int *A)
{
    if(heapSize<1)
    {
       printf("underflow");
       return -1;
    }
    int maximum=A[1];
    A[1]=A[heapSize];
    heapSize=heapSize-1;
    max_heapify(A,heapSize,1);
    return maximum;
}
void heap_increase_key(int *A, int i, int key)
{
    int p;
    if(key < A[i])
    {
        A[i]=key;
        max_heapify(A,heapSize,i);
    }
    else
        A[i]=key;
    while(i >1 && A[parent(i)]<A[i])
    {

        p=A[i];
        A[i]=A[parent(i)];
        A[parent(i)]=p;

        i=parent(i);
    }

    print_array(A,heapSize);
}


// Inserts the element key into the max priority queue A
void heap_insert(int *A, int key)
{
    heapSize=heapSize+1;
    A[heapSize]=-100000;
    heap_increase_key(A,heapSize,key);

}


int main()
{
    int opCode;
    int A[SIZE]; // The max priority queue

    printf("Operation codes:\n\n1. Max element\n2. Remove max element\n3. Insert element\n4. Exit\n\n");

    while(true)
    {
        printf("\n\nEnter operation code: ");

        scanf("%d", &opCode);

        if(opCode == 1)
        {
            printf("Max element is: %d",heap_maximum(A));
        }
        else if(opCode == 2)
        {
            // Your code
           printf(" %d ",heap_extract_max(A));
           print_array(A,heapSize);
        }
        else if(opCode == 3)
        {
            // Your code
           int key;
           printf("Enter a number to insert: ");
           scanf("%d",&key);
           heap_insert(A,key);
        }
        else if(opCode == 4)
            break;
        else
            puts("Invalid code.\n");
    }

    return 0;
}
