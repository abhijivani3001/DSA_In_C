// Merge Sort
#include<stdio.h>
#include<stdlib.h>

void merge(int *arr,int l,int m,int r){
    int n1=m-l+1;
    int n2=r-m;
    int leftArr[n1],rightArr[n2];
    for(int i=0;i<n1;i++) leftArr[i]=*(arr+(l+i));
    for(int i=0;i<n2;i++) rightArr[i]=*(arr+(m+1+i));
    int i=0,j=0,k=l;
    while(i<n1 && j<n2){
        if(leftArr[i]<=rightArr[j]){
            *(arr+k)=leftArr[i++];
        }
        else{
            *(arr+k)=rightArr[j++];
        }
        k++;
    }
    while(i<n1){
        *(arr+k)=leftArr[i++]; k++;
    }
    while(j<n2){
        *(arr+k)=rightArr[j++]; k++;
    }
}

void mergeSort(int *arr,int l,int r){
    if(l<r){
        int mid=(l+r)/2;
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);
        merge(arr,l,mid,r);
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
    mergeSort(arr,0,n-1);
    printf("\n*** Sorted Array ***\n");
    for(int i=0;i<n;i++)
        printf("%d ",*(arr+i));
    printf("\n");
    return 0;
}
