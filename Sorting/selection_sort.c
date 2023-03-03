// Selection Sort
#include<stdio.h>
#include<stdlib.h>

// Function definition to swap two numbers
void swap(int* a,int* b){
    // int temp=*a;
    // *a=*b;
    // *b=temp;
    *a=*a-*b;
    *b=*a+*b;
    *a=*b-*a;
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
    for(int i=0;i<n-1;i++){
        int min_idx=i;
        for(int j=i+1;j<n;j++){
            if(*(arr+j)<*(arr+min_idx)) min_idx=j;
        }
        if(min_idx!=i) swap(arr+min_idx,arr+i);
    }
    printf("\n*** Sorted Array ***\n");
    for(int i=0;i<n;i++)
        printf("%d ",*(arr+i));
    printf("\n");
    return 0;
}
