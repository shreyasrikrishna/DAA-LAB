#include<stdio.h>
#include<stdlib.h>

void quicksort(int *arr,int l,int r,int *op){
    if (r<=l)
    return ;//only one element

    int piv=arr[l];
    int s,i,j;
    int temp;
    i=l+1;
    j=r;
    while(1){
       
        while(arr[i]<=piv&&i<=r+1){
            (*op)++;
            i++;
        }

        while(arr[j]>piv&&j>l){
            (*op)++;
            j--;
        }
        if(j>i){
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
        else{
            //printf("\nreached22");            
            arr[l]=arr[j];            
            arr[j]=piv;            
            s=j;
            break;
        }
    }

    int nl1,nr1,nl2,nr2;
    nl1=l;
    nr1=s-1;
    nl2=s+1;
    nr2=r;   

    quicksort(arr,nl1,nr1,op);    
    quicksort(arr,nl2,nr2,op); 
}

int main(){   

    int opcount=0;

    int arr[20];
   
    for(int j=1;j<5;j++) {
        opcount=0;

        for(int i=0;i<j*5;i++){
            arr[i]=j*5-i;
        }
        
        printf("\nUnsorted array\n\n");

        for(int i=0;i<j*5;i++){
            printf("%d ",arr[i]);
        }

        quicksort(arr,0,j*5-1,&opcount);

        printf("\nsorted array\n\n");

        for(int i=0;i<j*5;i++){
            printf("%d ",arr[i]);
        }

        printf("\n opcount is %d\n\n",opcount);
    }
}