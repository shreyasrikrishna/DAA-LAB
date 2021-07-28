#include<stdio.h>

int intMethodGcd(int m,int n){
    int opcount=0;
    int min=m>n?n:m;
    if(min==0){
        opcount++;
        printf("opcount is %d\n",opcount);
        return 1;
    }

    while(min>=1){
        opcount++;
        if(m%min==0&&n%min==0){
            printf("opcount is %d\n",opcount);
            return min;
        }
        min--;
    }
}

int main(){
    int m,n;
    printf("enter the numbers for gcd calculation");
    scanf("%d %d",&m,&n);
    int res=intMethodGcd(m,n);
    printf("gcd is %d",res);
    return 0;

}