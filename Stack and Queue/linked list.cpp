#include<iostream>

struct node{
    int data;
    struct node * next;
};

void insert_begin(struct node ** q,int x){
    struct node * new_node = new node;
    new_node->data=x;
    new_node->next=*q;
    *q = new_node; 
}

int main()

{
    struct node * head;
    insert_begin(&head,10);

}