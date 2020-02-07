#include<stdio.h>
#include<stdlib.h>
#define PQSIZE 100
#define compare(a,b) a>b
#define parent(i) (i-1)/2
typedef int item;
typedef struct{
	item key[PQSIZE];
	int n;
}heap;
void swap(item* a,item* b)
{
	item temp=*a;
	*a=*b;
	*b=temp;
}
void heapify(item A[],int i,int heapsize)
{
	int selected=i,l=2*i+1,r=2*i+2;
	if(l<heapsize && compare(A[l],A[selected]))
		selected=l;
	if(r<heapsize && compare(A[r],A[selected]))
		selected=r;
	if(selected!=i)
	{
		swap(&A[selected],&A[i]);
		heapify(A,selected,heapsize);	
	}
}
void buildheap(item A[],int heapsize)
{
	for(int i=heapsize/2;i>=0;i--)
		heapify(A,i,heapsize);
}
void heapsort(heap* h)
{
	buildheap(h->key,h->n);
	for(int i=h->n-1;i>0;i--)
	{
		swap(&h->key[i],&h->key[0]);
		heapify(h->key,0,i-1);
	}
}
item remove(heap* h)
{
	if(h->n == 0)
	{
		printf("remove failed! heap empty");
		exit(0);
	}
	item temp=h->key[0];
	h->key[0]=h->key[--h->n];
	heapify(h->key,0,h->n);
	return temp;
}
void update(heap* h,int i,int nVal)
{
	if(h->key[i] > nVal)
	{
		h->key[i]=nVal;
		heapify(h->key,i,h->n);
	}
	else
	{
		h->key[i]=nVal;
		h->key[i]=nVal;
		while(i>0 && compare(h->key[i],h->key[parent(i)]))
		{
			swap(&h->key[i],&h->key[parent(i)]);
			i=parent(i);
		}		
			
	}
}

void insert(heap* h,int nVal)
{
	if(h->n == PQSIZE)
	{
		printf("insert failed! heap full");
		exit(0);
	}
	else
	{
		int i=h->n++;
		int p=(i-1)/2;
		h->key[i]=nVal;
		while(i>0 && compare(h->key[i],h->key[p]))
		{
			swap(&h->key[i],&h->key[p]);
			i=p;
			p=(i-1)/2;
		}		
			
	}
}
int main(){
	
	heap h;
	/*h.n=10;
	h.key[0]=12;h.key[1]=2;h.key[2]=92;h.key[3]=4;h.key[4]=17;
	h.key[5]=34;h.key[6]=48;h.key[7]=19;h.key[8]=9;h.key[9]=3;
	heapsort(&h);*/
	h.n=0;
	insert(&h,12);
	insert(&h,2);
	insert(&h,92);
	insert(&h,4);
	insert(&h,17);
	insert(&h,34);
	insert(&h,48);
	insert(&h,19);
	insert(&h,9);
	insert(&h,3);	
	for(int i=0;i<h.n;i++){
		printf("%d ",h.key[i]);
	}
	printf("\n");
	remove(&h);
	for(int i=0;i<h.n;i++){
		printf("%d ",h.key[i]);
	}
	return 0;
} // end of main




