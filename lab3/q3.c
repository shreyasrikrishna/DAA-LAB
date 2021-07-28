#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define size 50

void getPowerSet(int arr[], int set_size,int sum)
{
    
    int check=0;
    int flag=0;
    unsigned int pow_set_size = pow(2, set_size);
    int counter, j,i;
 
    /*Run from counter 000..0 to 111..1
     each value of the counter reprensents a combination of
     elements from the set in binary */
    for(counter = 0; counter < pow_set_size; counter++)
    {  
      check=0;
      
      for(j = 0; j < set_size; j++)
       {
          
          if(counter & (1<<j))
            check+=arr[j];
       }

       if(check==sum){ 
        
        flag=1;
         break;
       }
    }

    //check if a partition was found 
    if(!flag){
      printf("\n No partition was found ");
      return;
    }

    // if found , display the partition 

    int *indices= (int*)calloc(set_size,sizeof(int));

    for(j = 0; j < set_size; j++)
       indices[j]=0;  

    for(j = 0; j < set_size; j++)
     {
      if(counter & (1<<j))
        indices[j]=1; // marking elements that are in one set
     }

    printf("\n The sets are : ");


    printf("\n { ");
       for(j=0;j<set_size;++j){
           if(indices[j]==0)
             printf("%d ",arr[j]);
       }
    printf(" } \t and ");

    printf("\t { ");
       for(j=0;j<set_size;++j){
           if(indices[j]==1)
             printf("%d ",arr[j]);
       }
    printf(" } \n ");

}

int main(){

    int* arr;
    int n,i,sum=0;

    printf("\n Enter the number of elements in the set : ");
    scanf("%d",&n);
    
    arr=(int*)calloc(n,sizeof(int));

    printf("\n Enter the elements of the set : ");
      for(i=0;i<n;++i){
          scanf("%d",&arr[i]);
      }
        
       printf("\n");
       for(i=0;i<n;++i){
           sum+=arr[i];
          printf("%d ",arr[i]);
      }

      if(sum%2 == 0){
          sum=sum/2;
          getPowerSet(arr,n,sum);
      }

    else 
      printf("\n No partition was found ");

    return 0;

}
