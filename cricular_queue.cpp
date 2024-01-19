#include<iostream>
#define MAX 5

struct Q{
    int front;
    int rear;
    int pq[MAX];
};

void push(struct Q * q, int x){
    if(q->front==-1){
        q->front=((q->front)+1)%MAX;
        q->rear = q->front;
        q->pq[q->front]=x;
        return;
    }
    if(q->front==0 && q->rear==MAX-1){
        return;
    }
    if(q->front==(q->rear)+1){
        return;
    } // q->front == ((q->rear)+1)%MAX; this is also the complete overflow conditon!
    q->rear=(q->rear+1)%MAX;
    q->pq[q->rear]=x;
}

int pop(struct Q * q){
    if(q->front==-1){
        return NULL;
    }
    int item = q->pq[q->front];

    if(q->front==q->rear){
        q->front=-1;
        q->rear=-1;
        return item;
    }
    else{
        q->front = ((q->front)+1)%MAX;
        return item;
    }

}

int main(){

}