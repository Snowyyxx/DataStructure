#include<iostream>
#define MAX 8

struct Q{
    int pq[MAX];
    int front;
    int rear;
};

void init(struct Q *q){
    q->front=-1;
    q->rear=-1;
}

void enqueue_from_rear(struct Q * q, int num){
    
    if(q->front==(q->rear+1)%MAX){
        std::cout<<"overflow"<<std::endl;
        return; // checked overflow
    }
    if(q->front==-1){
        q->front=0; // checked if no element is inserted
    }
    if(q->rear==MAX-1){
        q->rear=0; // checked if rear is at max position
    }
    else{
        q->rear = q->rear+1;
    }   
    q->pq[q->rear]=num;
}

void enqueue_from_front(struct Q * q, int num){
    if(q->front == (q->rear+1)%MAX){
        return;
    }

    if(q->front==-1){
        q->front=MAX-1;
    }
    else{
        q->front=q->front-1;
    }
    q->pq[q->front]=num;
}
int dequeue_from_front(struct Q * q){
    

    if(q->front==-1){
        return NULL;
    }
    int temp =q->pq[q->rear];
    if(q->front==q->rear){
        q->front=-1;
        q->rear=-1;
    }
    else
    {
        q->front=q->front+1;
    }
    return temp;
}
int dequeue_from_rear(struct Q * q){
    // rear=rear-1;   
    
    if(q->front==-1){
        return NULL; // underflow ie 0 elements
    }
    int temp =q->pq[q->rear]; 

    if(q->rear==q->front){
        q->rear=-1; // singel element
        q->front=-1;
    }

    else if(q->rear==0){
        q->rear=MAX-1; // edge case
    }

    else{
        q->rear=q->rear-1; // general case
    }
    return temp;
}

int main(){

}