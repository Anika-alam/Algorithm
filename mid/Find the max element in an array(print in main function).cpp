Ques: Find the max element in an array(print in main function)


#include<stdio.h>
#include<conio.h>
int size;
int max_element(int arr[]){

   int i=0,max =-9999;
  
    if(i < size){
         if(max<arr[i])
           max=arr[i];
      i++;
      max_element(arr);
    }

    return max;
	getch();
}


int main(){

    int arr[1000],max,i,size;

    printf("Enter the size of the array: ");
    scanf("%d",&size);

    printf("Enter %d elements of an array: ", size);
    for(i=0;i<size;i++)
      scanf("%d",&arr[i]);

    max=max_element(arr);

    printf("Largest element of an array is: %d",max);
	getch();
    return 0;
}

