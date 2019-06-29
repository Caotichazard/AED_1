#include <stdlib.h>
#include <stdio.h>


typedef struct pilha
{
    char *stack;
    int tamMax;
    int curSize;
}pilha;


pilha* criaPilha(int tamMax);
void empilha(pilha *pilha,char c);
void desempilha(pilha *pilha);
void imprimePilha(pilha *pilha);
void organizaPilha(pilha *pilha);


int main(){
    pilha *a;
    
    a = criaPilha(100);
    for(int i =0; i<11;i++){
        empilha(a,'a');
    }
    empilha(a,' ');
    for(int i =0; i<11;i++){
        empilha(a,'a');
    }
    imprimePilha(a);
    //printf("%d", a->curSize);
    organizaPilha(a);   

    /*for(int i =0; i<11;i++){
        desempilha(a);
    }  
    imprimePilha(a);
    */
    
}


pilha* criaPilha(int tamMax){
    pilha *new_stack = malloc(sizeof(pilha));
    char *stack = malloc(sizeof(int)*tamMax);
    new_stack->tamMax = tamMax;
    new_stack->stack = stack;
    new_stack->curSize = 0;
    return new_stack;
}

void empilha(pilha *pilha,char c){
    if(pilha->curSize==pilha->tamMax){
        printf("pilha ja esta cheia\n");
    }else{
        pilha->stack[pilha->curSize] = c;
        pilha->curSize++;
    }
}

void desempilha(pilha *pilha){
    if(pilha->curSize == 0){
        printf("pilha está atualmente vazia\n");
    }else{
        pilha->curSize--;
    }
}

void imprimePilha(pilha *pilha){
    for (int i=0;i<pilha->curSize;i++){
        printf("%c..", pilha->stack[i]);
    }
    printf("\n");
}

void organizaPilha(pilha *pilha){
    int ready = 0;
    int i = 0, wordLen=0,initWord;
    int tamMax = pilha->curSize;
    while(i < tamMax){
        wordLen=0;
        if(pilha->stack[i] == ' '){
            i++;
        }
        while (pilha->stack[i] != ' ')
        {
            wordLen++;
            i++;
        }
        //printf("%d", i);
        //printf("tam palavra atual: %d\n", wordLen);
        printf("%d..%d\n",pilha->curSize,i);    
        
        
        
    }
}