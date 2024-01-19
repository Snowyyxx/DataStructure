#include<iostream>

struct node{
    int data;
    struct node * next;
};

void add_cir(struct node ** f, struct node ** r, int x){
    struct node * temp;
    temp->data= x;

    if(temp==NULL){
        return;
    }

    if(*f==NULL){
        *f = temp;
    }
    else 
    {
        (*r)->next = temp;
    }
    *r = temp;
    return;

}

int del_cir(struct node **f, struct node **r){
    struct node * temp;
    int item;
    if(*f==NULL){
        return NULL;
    }

    if(*f==*r){
        item = (*f)->data;
        temp = *f;
        *f=NULL;
        *r=NULL;
        free(temp);
        return item;
    }

    item = (*f)->data;
    temp = *f;
    *f = (*f)->next;
    (*r)->next=*f;
    free(temp);
    return item;
}

void insertion_after_value(struct node** f, struct node **r , int num, int x){
    struct node * temp;
    temp->data=x;

    if(*f==NULL){
        *f=temp;
    }
    struct node * dummy = *f;
    while(dummy!=*r){
        if(dummy->data==num){
            break;
        }
        dummy=dummy->next;
    }
    if(dummy==*r &&dummy->data!=x){
        return;
    }
    else{
        temp->next = dummy->next;
        dummy->next=temp;
    }
}

int main()
{
    
}