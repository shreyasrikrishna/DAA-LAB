#include<stdio.h>
#include<stdlib.h>

typedef struct recordFactors{
    int size;
    int factor[100];
    int exp[100];
}*RECORD;

int findFactors(int a, RECORD r){
    int c=0;
    int k=1;
    int opcount=0;
    r->factor[0]=1;
    r->exp[0]=1;
    
    for(int i=2;i<=a;i++){
        c=0;

        while(1){
            opcount++;//checking for a%i is the basic operation so counting the number of checks
            if(a%i==0){
             c++;
             a=a/i;
             }
            else break;
        }
        if(c>0){
            r->factor[k]=i;
            r->exp[k]=c;
            k++;
        }
    }
    r->size=k;
    return opcount;
}

void displayFactors(RECORD r){
    for(int i=0;i<r->size;i++){
        printf("%d ^ %d\n",r->factor[i],r->exp[i]);
    }
}

int findCommon(RECORD m, RECORD n){
    int gcd=1;
    int i=1,j=1,min=1;
     
    while( i<m->size&&j<n->size){
        //since factor arrays will be sorted 
        if(m->factor[i]<n->factor[j])
            i++;
        else if(n->factor[i]<m->factor[j])
            j++;
        else {
            min=m->exp[i]>n->exp[j]?n->exp[j]:m->exp[i];
            for(int k=1;k<=min;k++){
                gcd=gcd*(m->factor[i]);
            }
            i++;
            j++;
        }
    }
    return gcd;
}

int middleSchoolGcd(int m,int n){
    RECORD mfactors,nfactors;
    mfactors=(RECORD)malloc(sizeof(struct recordFactors));
    nfactors=(RECORD)malloc(sizeof(struct recordFactors));

    int op1=findFactors(m,mfactors);
    printf("Factors for %d\n",m);
    displayFactors(mfactors);
    
    int op2= findFactors(n,nfactors);
    printf("Factors for %d\n",n);
    displayFactors(nfactors);

    printf("opcount is %d\n",op1+op2);

    return findCommon(mfactors,nfactors);
}

int main(){
    int m,n;
    printf("enter the numbers for gcd calculation");
    scanf("%d %d",&m,&n);
    int res=middleSchoolGcd(m,n);
    printf("gcd is %d",res);
    return 0;
}