// WAP to implement a student structure using dynamic memory allocation and 
// perform following operations
// (i) Create a student record
// (ii) Search a student record
// (iii) Update a student record
// (iv) Delete a student record
// (v) Display student records
// (vi) Sort student records
// (vii) Merge student records
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int n;
typedef struct student{
    int rollno;
    char name[50];
    float spi;
}st;

// Create a student record
void create(st *p, int a){
    int i;
    for(i=0;i<a;i++){
        printf("Student %d :- Enter your Name : ",i+1);
        scanf("%s",(p+i)->name);
        printf("Student %d :- Enter your Roll No : ",i+1);
        scanf("%d",&(p+i)->rollno);
        printf("Student %d :- Enter your SPI : ",i+1);
        scanf("%f",&(p+i)->spi);
    }
}
// Search a student record
void search(st *p, int a){
    int i,r,found=0;
    printf("Enter Roll No to Search : \n");
    scanf("%d",&r);
    for(i=0;i<a;i++){
        if(r==((p+i)->rollno)){
            printf("Name : %s\nRoll No : %d\nSPI : %f\n",(p+i)->name,(p+i)->rollno,(p+i)->spi);
            found=1;
            break;
        }
    }
    if(!found){
        printf("\nStudent record not found!\n");
    }
}
// Update a student record
void update(st *p, int a){
    int up,found=0,i;
    printf("Enter Roll No to Update : \n");
    scanf("%d",&up);
    for(i=0;i<a;i++){
        if(up==(p+i)->rollno){
            printf("Enter new Name : ");
            scanf("%s",(p+i)->name);
            printf("Enter new Roll No : ");
            scanf("%d",&(p+i)->rollno);
            printf("Enter new SPI : ");
            scanf("%f",&(p+i)->spi);
            found=1;
            break;
        }
    }
    if(!found){
        printf("\nWorng Roll No entered!\n");
    }
}
// Delete a student record
void delete(st *p, int a){
    int del,i,j,found=0;
    printf("Enter Roll No to Delete : ");
    scanf("%d",&del);
    for(i=0;i<a;i++){
        if(del==(p+i)->rollno){
            found=1;
            break;
        }
    }
    if(!found){
        printf("\nStudent record not found!\n");
        return;
    }
    for(j=i;j<a-1;j++){
        (p+j)->rollno=(p+j+1)->rollno;
        strcpy((p+j)->name, (p+j+1)->name);
        (p+j)->spi=(p+j+1)->spi;
    }
    n--;

}
// Display a student record
void display(st *p, int a){
    int i;
    for(i=0;i<a;i++){
        printf("\nStudent %d :- Name : %s\n",i+1,(p+i)->name);
        printf("Student %d :- Roll No : %d\n",i+1,(p+i)->rollno);
        printf("Student %d :- SPI : %f\n",i+1,(p+i)->spi);
    }
}
// Sort a student record
void sort(st *p, int a){
    int i,j,t1;
    char t2[50];
    float t3;
    for(i=0;i<a;i++){
        for(j=i+1;j<a;j++){
            if((p+i)->rollno > (p+j)->rollno){
                t1=(p+i)->rollno;
                (p+i)->rollno=(p+j)->rollno;
                (p+j)->rollno=t1;

                strcpy(t2, (p+i)->name);
                strcpy((p+i)->name, (p+j)->name);
                strcpy((p+j)->name, t2);

                t3=(p+i)->spi;
                (p+i)->spi=(p+j)->spi;
                (p+j)->spi=t3;
            }
        }
    }
    printf("***** Sorted student record : *****\n");
    display(p, a);
}
// Merge a student record
void merge(st *p, int a, int b){
    int k;
    for(k=0;k<b;k++){
        printf("New Student %d :- Enter your Name : ",k+1);
        scanf("%s",(p+k+a)->name);
        printf("New Student %d :- Enter your Roll No : ",k+1);
        scanf("%d",&(p+k+a)->rollno);
        printf("New Student %d :- Enter your SPI : ",k+1);
        scanf("%f",&(p+k+a)->spi);
    }
    printf("\n***** New Student Record *****\n\n");
    display(p, a+b);
}

int main(){
    int ch,i;
    int m;
    printf("Enter the number of students : \n");
    scanf("%d",&n);
    st *ptr;
    // Syntax: ptr_variable = (data_type*)malloc(size_in_bytes); 
    ptr=(st*)malloc(n*sizeof(st));
    
    while(1){
        printf("\n**************************************\n");
        printf("Enter 1 for Create a student record\n");
        printf("Enter 2 for Search a student record\n");
        printf("Enter 3 for Update a student record\n");
        printf("Enter 4 for Delete a student record\n");
        printf("Enter 5 for Display a student record\n");
        printf("Enter 6 for Sort a student record\n");
        printf("Enter 7 for Merge a student record\n");
        printf("Enter 0 for Exit a student record\n");
        printf("**************************************\n\n");
        
        printf("Enter your choice : \n");
        scanf("%d",&ch);
        if(ch==0)
            break;
        
        switch(ch){
            case 1:
                create(ptr, n);
                break;
            case 2:
                search(ptr, n);
                break;
            case 3:
                update(ptr, n);
                break;
            case 4:
                delete(ptr, n);
                break;
            case 5:
                display(ptr, n);
                break;
            case 6:
                sort(ptr, n);
                break;
            case 7:
                printf("Enter how many new student record you wants to add : ");
                scanf("%d",&m);
                // Syntax: ptr_variable = (data_type*)realloc(ptr_variable, size_in_bytes);
                ptr=(st*)realloc(ptr, m*sizeof(st));
                merge(ptr, n, m);
                break;
            default:
                printf("Please enter valid choice!\n");
        }
    }
    free(ptr); // Memory becomes free
    return 0;
}