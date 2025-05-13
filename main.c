#include <stdio.h>
#include <stdlib.h>
void swap(int *x,int *y){
       int temp = *x;
       *x = *y;
       *y = temp;
       }

void wiggleSort1(int a[], int size){

  for(int i=0;i<size -1;i++){

        if ((i%2==1 && a[i]<=a[i+1])||
            (i%2==0 && a[i]>=a[i+1])){

            swap(&a[i],&a[i+1]);
        }


        //if (i%2==0 && a[i]>a[i-1]){
           // swap(&a[i],&a[i-1]);}
  }

printf("\nElements in array after sort are: ");

    for(int i=0; i<size; i++)
    {
        printf("%d  ", a[i]);
    }
    printf("\n");
}

int main()
{
    int a[10000];
    printf("Enter size of array");

        int size;
        scanf("%d", &size);

    printf("Enter array to sort");

        for(int i=0; i<size; i++)
    {

        scanf("%d", &a[i]);
    }
    printf("\nElements in array before sort are: ");
    for(int i=0; i<size; i++)
    {
        printf("%d  ", a[i]);
    }
    printf("\n");
    wiggleSort1(a,size);
    return 0;
}

