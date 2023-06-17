// Linear Search
#include<stdio.h>
#include<stdlib.h>

int main(){
    int n,k,flag=1;
    printf("Enter the number of elements : ");
    scanf("%d",&n);
    int *arr=(int*)malloc(n*sizeof(int));
    for(int i=0;i<n;i++){
        printf("Enter the Element %d : ",i+1);
        scanf("%d",arr+i);
    }
    printf("Enter the Number, which you want to find in Array : ");
    scanf("%d",&k);
    for(int i=0;i<n;i++){
        if(*(arr+i)==k){
            printf("Number %d is found at Index %d\n",k,i+1);
            flag=0;
        }
    }
    if(flag) printf("Number %d is not found in given Array!!\n",k);
    return 0;
}