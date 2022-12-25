// C program to multiply two matrix using pointers
#include<stdio.h>
#include<stdlib.h>

void MatrixInput(int *p, int row, int col){
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            scanf("%d",(p+(i*col+j)));
        }
    }
}

int main(){
    int arow,acol,brow,bcol;
    printf("Enter the number of rows for Matrix A : ");
    scanf("%d",&arow);
    printf("Enter the number of columns for Matrix A : ");
    scanf("%d",&acol);
    int *aptr;
    aptr=(int*)malloc(arow*acol*sizeof(int));

    printf("Enter the number of rows for Matrix B : ");
    scanf("%d",&brow);
    printf("Enter the number of columns for Matrix B : ");
    scanf("%d",&bcol);
    int *bptr;
    bptr=(int*)malloc(brow*bcol*sizeof(int));

    if(acol!=brow){
        printf("Matrix multiplication not possible!");
        exit(1);
    }

    printf("Enter the values of matrix A : \n");
    MatrixInput(aptr, arow, acol);
    printf("Enter the values of matrix B : \n");
    MatrixInput(bptr, brow, bcol);

    int *cptr;
    cptr=(int*)calloc(arow*bcol, sizeof(int));
    
    for(int i=0;i<arow;i++){
        for(int j=0;j<bcol;j++){
            for(int k=0;k<acol;k++){
                *(cptr+i*bcol+j) += (*(aptr+i*acol+k)) * (*(bptr+k*bcol+j));
            }
        }
    }
    
    printf("\n***** Matrix Multiplication *****\n\n");
    for(int i=0;i<arow;i++){
        for(int j=0;j<bcol;j++){
            printf("%d ",*(cptr+i*bcol+j));
        }
        printf("\n");
    }
    return 0;
}