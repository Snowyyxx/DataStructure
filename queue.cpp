#include<iostream>
#define MAX 5

struct node {
    int data;
    struct node * next;
};


void push(struct node ** front, struct node ** rear, int x){
    struct node * temp = new node;
    temp->data=x;
    if(*front==NULL){
        *front =temp;
        *rear=*front;
    }
    if(!temp){
        return;
    }
    (*rear)->next = temp;
    *rear = temp;
}

int pop(struct node ** front, struct node ** rear){
    struct node * temp = new node;
    if(!(*front)){
        return NULL;
    }
    int item;
    if(*front==*rear){
        temp =*front;
        item = (*front)->data;
        free(temp);
        return item;
    }
    temp = *front;
    item = temp->data;
    *front = (*front)->next;
    free(temp);
    return item;
}


int main(){
    struct node * node;
    struct node ** top = &node;
    struct node ** rear = &node;
}

