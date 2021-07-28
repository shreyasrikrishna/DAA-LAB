#include<stdio.h>
#include<stdlib.h>

int main(){
    char *parent,*sub;
    int p,s,i;
    printf("enter length of parent string\n");
    scanf("%d",&p);
    parent=(char*)malloc(sizeof(char)*p);
    printf("enter parent string\n");
    scanf("%s",parent);
    printf("enter length of string to be matched\n");
    scanf("%d",&s);
    sub=(char*)malloc(sizeof(char)*s);
    printf("enter string to be matched\n");
    scanf("%s",sub);
    int j=0,flag=0;

    for( i=0;i<=p-s;i++){
        j=0;
        while(j<s&&parent[i+j]==sub[j]){
            
            j++;
            if(j==s){
                flag=1;
                break;
            }
        }
    }
    if(flag==1){
        printf("substring found!");
    }
    else printf("substring not found");


}