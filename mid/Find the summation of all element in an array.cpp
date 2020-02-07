Ques:Find the summation of all element in an array


#include<stdio.h>
#include<conio.h>
int size;
int getsumElement(int arr[]){
   int sum=0;
    int i;
    for (i =0; i<size; i++)
       sum +=arr[i];
    return sum;
	getch();
}

int main(){

    int arr[100],sum,i;

    printf("Enter the size of the array: ");
    scanf("%d",&size);

    printf("Enter %d elements of an array: ",size);
    for(i=0;i<size;i++)
      scanf("%d",&arr[i]);

    sum=getsumElement(arr);

    printf("sum of the element of an array is: %d",sum);
	getch();
    return 0;
}

