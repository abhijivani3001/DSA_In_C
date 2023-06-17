// Binary Search
#include<stdio.h>
#include<stdlib.h>

int main(){
    int n,k,flag=1;
    printf("Enter the number of elements : ");
    scanf("%d",&n);
    int *arr=(int*)malloc(n*sizeof(int));
    printf("*** Enter the Array elements in sorted order ***\n\n");
    for(int i=0;i<n;i++){
        printf("Enter the Element %d : ",i+1);
        scanf("%d",arr+i);
        if(i>0){
            if(arr+i<=arr+i-1){
                printf("Please enter valid numbers!!\n");
                break;
            }
        }
    }
    printf("Enter the Number, which you want to find in Array : ");
    scanf("%d",&k);
    int l=0,r=n-1,mid;
    while(l<=r){
        mid=(l+r)/2;
        if(k==*(arr+mid)){
            printf("Number %d is found at Index %d\n",k,mid+1);
            flag=0;
            break;
        }
        if(k>*(arr+mid)) l=mid+1;
        else if(k<*(arr+mid)) r=mid-1;
    }
    if(flag) printf("Number %d is not found in given Array!!\n",k);
    return 0;
}