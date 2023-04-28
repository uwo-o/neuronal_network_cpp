#ifndef DATA_STRUCTURES_H
#define DATA_STRUCTURES_H

typedef struct Stack{
    Node * head;
    void (* push)(Node);
    void (* pop)();
    int (* get_length)();
} Stack;

typedef struct Node{
    int value;
    struct Node * ptr_prev;
    struct Node * ptr_next;
} Node;

void push(Node node);
void pop();
int get_length();

#endif