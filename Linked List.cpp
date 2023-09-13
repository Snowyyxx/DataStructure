#include<iostream>

struct node{
    int data;
    struct node * next;
};

void insert_node_end(struct node** q,int num){
    struct node* new_node = new node;
    new_node->data=num;
    new_node->next=NULL;

    if(*q==NULL){
        return;
    }
    struct node* temp = *q;
    while (temp->next!=NULL){
      temp=temp->next;  
    }
    temp->next=new_node;
}

void insert_node_pos(struct node**q, int num, int pos){
    if(pos==-1){
        (*q)->data=num;
        (*q)->next=NULL;
        return;
    }
    struct node * new_node = new node;
    new_node ->data = num;
    new_node->next=NULL;
    struct node * temp= *q;
    for(auto i=0;i<pos;i++){
        temp=temp->next;
    }
    new_node->next=temp->next;
    temp->next=new_node;

}

int main(){

}