#include<stdio.h> 
#include<stdlib.h> 
#include<malloc.h> 
#include<string.h> 
#define MALLOC(p,s,t)\
if(!((p)=(t)malloc(s)))\
{\
    fprintf(stderr,"Insufficient Memory\n");\
    exit(EXIT_FAILURE);\
} 
struct List 
{ 
    char word[500]; 
    struct List* next; 
}; 
typedef struct List* NODE; 
int flag=0,f=0; 
int count=0; 
void printword(NODE first) 
{ 
    NODE cur = first; 
    while(cur!=NULL) 
    { 
        count++; 
        printf("%s ",cur->word); 
        if(count%2!=0)
        { 
            (f++); 
        } 
        else if(count==2) 
        { 
            printf("\n"); 
            count=0; 
            flag++; 
        } 
        else 
        { 
        
            printf("\n"); 
        
        } 

        cur=cur->next; 
    } 
} 
void main() 
{ 
    char word[500]; 
    char *c; 
    NODE first  = NULL; 
    NODE prev = NULL;

    NODE cur; 
    printf("Enter any sentence of your choice:\n"); 
    fgets(word,500,stdin); 
    c = strtok(word," "); 
    while(c!=NULL) 
    { 
        MALLOC(cur,sizeof(struct List),NODE); 
        strcpy(cur->word,c); 
        cur->next=NULL; 
        if(first==NULL) 
        { 
            first=cur; 
        } 
        else 
        { 
            prev->next=cur; 
        } 
        prev=cur; 
        c=strtok(NULL," "); 
    } 
    printf("Your Resultant and Modified Sentence is:\n"); 
    printword(first); 
    if(count%2!=0) 
    { 
        printf("\nTotal number of lines to print your sentence is:%d\n",f); 
    } 
    else 
    { 
        printf("Total number of lines taken to print your sentence is:%d\n",flag); 
    } 
}