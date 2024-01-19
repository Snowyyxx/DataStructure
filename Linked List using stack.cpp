#include<iostream>

struct node{
    int data;
    struct node * next;
};


void push_insert_begin(struct node ** top,int x){
    struct node * new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data=x;
    new_node->next=NULL;

    if((*top)==NULL){
        *top = new_node;
        return;
    }
    new_node->next=(*top)->next;
    *top = new_node;
}

int pop(struct node ** top){
    if((*top)==NULL){
        return NULL;
    }
    struct node * temp = *top;
    int item = temp->data;
    *top=(*top)->next;
    delete(temp);
    return item;
}

void free_all(struct node **top){
    struct node * temp = *top;
    while((*top)!=NULL){
        temp = *top;
        *top=(*top)->next;
        delete(temp);
    }
}

