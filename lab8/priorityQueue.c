#include<stdio.h>
#include<stdlib.h>

void heapify(int arr[],int n){
    int i,v,j;
    int heap=0,k=0;
    for(i=n/2;i>=1;i--){
        k=i;
        v=arr[i];
        while(!heap&&2*k<n){            
            j=2*k;
            if(arr[j+1]>arr[j])
                j++;
            if(v>arr[j]){
                heap=1;
                continue;
            }
            else{
                arr[k]=arr[j];//swapping parent w larger kid
                k=j;//to check if this spoils any lower parent-kid heaps
            }
        }
        arr[k]=v;//at the end of while loop we find the correct pos for v depending on how many swaps were needed
    }
}

void topdown(int arr[], int insertIndex){
    int curr=insertIndex;//just for ease
    int parent=curr/2;
    while(parent>=1){
        if(arr[parent]<arr[curr]){
            int temp=arr[parent];
            arr[parent]=arr[curr];
            arr[curr]=temp;
            curr=parent;
            parent=curr/2;
        }
        else{
            break;
        }
    }
}

int insert(int arr[],int n,int val){
    n=n+1;
    arr[n]=val;
    topdown(arr,n);
    printf("\ncurrent heap");
    for(int i=1;i<=n;i++){
        printf("%d ",arr[i]);
    }
    return n;

}

int maxDel(int arr[],int n){
    int temp=arr[n];
    arr[n]=arr[1];
    printf("last ele %d\n",arr[n]);
    arr[1]=temp;
    heapify(arr,n-1);
    return n-1;
}

int main(){
    int arr[100];
    arr[0]=0;
    int n=0;
    printf("inserting into queue\n");
    for(int i=0;i<5;i++){
        n=insert(arr,n,i+2);
    }
    
    printf("dequeing a few\n");
    for(int i=0;i<3;i++){
        printf(" dequeue number %d\n",i+1);
        n=maxDel(arr,n);
        printf("dequeued %d\n",arr[n+1]);
    }
}