#include "data_structures.h"

void push(Stack * stack, Node * node){
    
    if(stack->head == NULL){
        stack->head = node;
        node->ptr_next = NULL;
    }else{
        Node * aux = stack->head;
        stack->head = node;
        node->ptr_next = aux;
    }
}

void pop(Stack * stack){

    if(stack->head == NULL){
        return;
    }

    Stack * aux = stack->head;
    stack->head = stack->head->ptr_next;
    free(aux);
}

int get_length(Node * head){

    int length = 0;

    Node * current = head;

    while(current != NULL){
        length++;
        current = current->ptr_next;
    }

    return length;
}