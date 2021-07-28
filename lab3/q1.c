#include<stdio.h>
#include<stdlib.h>

void bubbleSort(int *arr,int n){
    int opcount=0;
    int keyswap=0;
    int temp;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            opcount++;
            if(arr[j]>arr[j+1]){
                keyswap++;
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    printf("\nopcount is %d and key swap count is %d\n",opcount,keyswap);
}

int main(){
    int *arr;
    int i,j;
    int n=5;
    for(int j=0;j<4;j++){
        arr=(int*)malloc(n*sizeof(int));
        for(int k=0;k<n;k++){
            arr[k]=n-k;
        }
        printf("initial array\n");
        for(int k=0;k<n;k++){
            printf("%d ",arr[k]);
        }
        bubbleSort(arr,n);
        printf("after sorting\n");
        for(int k=0;k<n;k++){
            printf("%d ",arr[k]);
        }

        printf("\n\n");
        free(arr);
        n+=5;
    }
}

