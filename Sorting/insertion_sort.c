// Insertion Sort
#include<stdio.h>
#include<stdlib.h>

void insertionSort(int a[],int n){
    int temp,j;
    for(int i=1;i<n;i++){
        temp=a[i];
        j=i-1;
        while((j>=0) && (a[j]>temp)){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=temp;
    }
}

int main(){
    int n; // n=Number of elements in the array
    printf("Enter the number of elements : ");
    scanf("%d",&n);
    int *arr=(int*)malloc(n*sizeof(int));
    for(int i=0;i<n;i++){
        printf("Enter the Element %d : ",i+1);
        scanf("%d",arr+i);
    }
    insertionSort(arr,n);
    printf("\n*** Sorted Array ***\n");
    for(int i=0;i<n;i++)
        printf("%d ",*(arr+i));
    printf("\n");
    return 0;
}