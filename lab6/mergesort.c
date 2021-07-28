#include<stdio.h>
#include<stdlib.h>

int merge(int *arr,int *a,int *b,int na,int nb){
    int i=0,j=0,k=0;
    static int opcount;
        
    while(i<na&&j<nb){
        opcount++; // for each comparison

        if(a[i]<b[j]){
            arr[k++]=a[i++];
        }
        else{
            arr[k++]=b[j++];
        }
    }
    
    while(i<na){
        arr[k++]=a[i++];
    }

    while(j<nb){
        arr[k++]=b[j++];
    }
    // printf("\nopcount is %d\n",opcount);
    return opcount;
    
}

int mergesort(int *arr,int n){
    if(n==1)
    return 0;

    int mid=n/2;    
    int na=mid;
    int nb=n-mid;
    int a[na];
    int b[nb];
   
    for(int i=0;i<na;i++){
        a[i]=arr[i];
    }

    for(int i=0;i<nb;i++){
        b[i]=arr[i+mid];
    }
  
   int temp=mergesort(a,na);
   temp=mergesort(b,nb);    
   int op=merge(arr,a,b,na,nb);
   return op;
   
}



int main(){
    int arr[5]={5,4,2,3,1};
    

    printf("\nbefore sort\n\n");

    for(int i=0;i<5;i++){
        printf("%d ",arr[i]);
    }

    int op=mergesort(arr,5);

    printf("\nsorted array\n\n");
   
    for(int i=0;i<5;i++){
        printf("%d ",arr[i]);
    }

    printf("\nopcount is %d\n",op);

    int array[10]={3,1,5,9,7,6,4,0,2,8};
    printf("\nbefore sort\n\n");

    for(int i=0;i<10;i++){
        printf("%d ",array[i]);
    }

     op=mergesort(array,10);

    printf("\nsorted array\n\n");
   
    for(int i=0;i<10;i++){
        printf("%d ",array[i]);
    }

    printf("\nopcount is %d\n",op);


    int array1[15]={3,1,11,13,5,9,7,6,4,0,14,2,12,10,8};
    printf("\nbefore sort\n\n");

    for(int i=0;i<15;i++){
        printf("%d ",array1[i]);
    }

     op=mergesort(array1,15);

    printf("\nsorted array\n\n");
   
    for(int i=0;i<15;i++){
        printf("%d ",array1[i]);
    }

    printf("\nopcount is %d\n",op);

    
}