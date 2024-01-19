#include<iostream>
#define max 5
struct Q{
    int pq[max];
    int front;
    int rear;
};

void enqueue(struct Q *q, int x){
    if(q->front == (q->rear+1)%max){
        return; // overflow condn
    }
    
    if(q->front==-1){
        q->front=0;
        q->rear=0;
        q->pq[q->front]=x;
        return;
    }
    q->rear = (q->rear+1)%max;
    q->pq[q->rear] = x;
}

int dequeue(struct Q * q){
    if(q->front==-1){
        return;
    }
    int item;
    if(q->front==q->rear){
        item = q->pq[q->front];
        q->front=-1;
        q->rear=-1;
        return item;
    }
    item = q->pq[q->front];
    q->front=(q->front+1)%max;
    return item;
}

int main(){

}