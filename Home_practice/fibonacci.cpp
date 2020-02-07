
#include<cstdio>
#include<ctime>
#include<cstdlib>
#include<cassert>
#include<algorithm>
#define sz 100000
#define MERGE 1
#define INS 2

int a[sz+5], b[sz+5], c[sz+5];

void merge(int A[],int p, int q, int r)
{
     int n1= q-p +1 ;
    int n2= r-q ;

    int L[n1+1] , R[n2+1] ;

    for(int i=0 ; i<n1; i++){
        L[i]= A[p+i];
    }
    for(int j=0 ; j<n2 ; j++){
        R[j]= A[q+1 + j ];
    }

    L[n1]=2147483647;
    R[n2]=2147483647;

    int s=0,t=0;
    for ( int k = p ; k <= r ; k++){
        if (L[s]<=R[t]){
            A[k]=L[s];
            s++;

        }else{

            A[k]= R[t];
            t++;

        }
    }

}


void merge_sort(int A[],int p, int r)
{
     int mid ;
    if(p<r){
        mid= (p+r)/2 ;
        merge_sort(A,p,mid);
        merge_sort(A,mid+1,r);
        merge(A,p,mid,r);
    }

}
void insertion_sort() {
    int i,j,temp,n;
    for(j=1; j<n; j++)
    {
        temp=a[j];
        i=j-1;
        while(i>=0 && a[i]>temp)
        {
            a[i+1]=a[i];
            i=i-1;

        }

        a[i+1]=temp;

    }
    for(i=0; i<n; i++)
    {
        printf(" %d ",a[i]);
    }


}

int sort_ok(int a[]) {
    for (int i=0;i<sz;++i)
        if (a[i] != c[i]) return 0;
    return 1;
}


int main() {
    /* do not change here */
    int A[100];
    printf("Enter 5 input\n");
    for(int i=0;i<sz;i++)
    {
        scanf("%d",&A[i]);

    }
    srand(time(NULL));
    for (int i=0;i<sz;++i) {
        a[i] = rand() % 1000;
        b[i] = a[i];
        c[i] = a[i];
    }


    std::sort(c, c+sz);

    clock_t s = clock();
    merge_sort(A,0,sz-1);
    clock_t e = clock();
    assert(sort_ok(a));
    printf("Time for merge sort: %d\n", e-s);

    s = clock();
    insertion_sort();
    e = clock();
    assert(sort_ok(b));
    printf("Time for insertion sort: %d\n", e-s);


    return 0;
}
