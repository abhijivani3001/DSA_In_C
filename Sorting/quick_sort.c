// Quick Sort
#include<stdio.h>
#include<stdlib.h>

// Function definition to swap two numbers
void swap(int* a,int* b){
    *a=*a-*b;
    *b=*a+*b;
    *a=*b-*a;
}

int partition(int a[],int low,int high){
    int pivot=a[low],start=low,end=high;
    while(start<end){
        while(a[start]<=pivot){
            start++;
        }
        while (a[end]>pivot){
            end--;
        }
        if(start<end) swap(&a[start],&a[end]);
        
    }
    swap(&a[low],&a[end]);
    return end;
}

void quickSort(int arr[],int l,int r){
    if(l<r){
        int pi=partition(arr,l,r);
        quickSort(arr,l,pi-1);
        quickSort(arr,pi+1,r);
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
    quickSort(arr,0,n-1);
    printf("\n*** Sorted Array ***\n");
    for(int i=0;i<n;i++)
        printf("%d ",*(arr+i));
    printf("\n");
    return 0;
}
