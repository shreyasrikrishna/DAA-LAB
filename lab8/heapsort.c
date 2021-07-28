#include <stdio.h>

int opcount=0;

void heapify(int h[], int n)
{
    int i, k, v, heapify, j;
    for (i = (n / 2); i >= 1; i--)
    {
        k = i;
        v = h[k];
        heapify = 0;
        while (heapify == 0 && 2 * k <= n)
        {
            j = 2 * k;
            opcount++;
            if (j < n)
                if (h[j] < h[j + 1])
                    j = j + 1;
            if (v >= h[j])
                heapify = 1;
            else
            {
                h[k] = h[j];
                k = j;
            }
        }
        h[k] = v;
    }
    return;
}

void MaxKeyDel(int heap[], int size)
{
    //exchanging max with last node
    int max = heap[1];
    heap[1] = heap[size];
    heap[size] = max;
    
    heapify(heap, size-1);
}

void heapsort(int heap[],int size){

    while(size > 0){
        MaxKeyDel(heap,size);
        size=size-1;
    }
}


void main()
{

    int h[20], i, n;
    printf("\nEnter the number of Elements:");
    scanf("%d", &n);
    printf("\nEnter the Elements:");
    for (i = 1; i <= n; i++)
        scanf("%d", &h[i]);
    
    printf("\ncurrent array: ");
   
    for (i = 1; i <= n; i++)    
        printf("%d ", h[i]);    
   
    heapify(h,n);
    heapsort(h, n);
    printf("\nThe sorted array :  ");
    for (i = 1; i <= n; i++)
    {
        printf("%d ", h[i]);
    }

    printf("\n Opcount = %d ",opcount);
}