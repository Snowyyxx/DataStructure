/*
Question: Let Q be a simple queue with n integers. isEmpty(Q) returns true if Q is 
empty,  false  otherwise.  dequeue(Q)  deletes  an  integer  at  the  front  of  Q 
and returns its value. enqueue(Q, i) inserts an integer i at the rear of Q. 
The task is to reverse the order of the integers in Q. Propose an efficient 
algorithm  or  pseudocode  for  the  same  using  constant  extra  space. Show 
it’s execution on a Q with 4 integers: (front) 4 6 1 9 (rear). 
*/
#include<iostream>
#define MAX 5

struct Q{
    int front;
    int rear;
    int pq[MAX];
};

void reverse_queue(struct Q* q) {
    int i = q->front;
    int j = q->rear;
    int temp;
    while (i != j && i != j-1) {
        temp = q->pq[i];
        q->pq[i] = q->pq[j];
        q->pq[j] = temp;

        i++;
        j--;

    }
}

void enqueue(struct Q *q, int x){
    if(q->rear==MAX-1){
        return;
    }
    if(q->front==-1){
        q->front=0;
        q->rear=q->rear+1;
        q->pq[q->front]=x;
        return;
    }
    q->rear = q->rear+1;
    q->pq[q->rear]=x;
}

bool isEmpty(struct Q* q){
    if(q->front==-1){
        return true;
    }
    return false;
}

int dequeue(struct Q * q){
    if(q->front==-1){
        return NULL;
    }
    int item;
    if(q->front==q->rear){
        item = q->pq[q->front];
        q->front=-1;
        q->rear=-1;
        return item;
    }
    item = q->pq[q->front];
    q->front=q->front+1;
    return item;
}

int main(){
    struct Q q;
    q.front = -1;
    q.rear=-1;
    for(int i=0;i<3;i++){
        enqueue(&q,i);
    }
    reverse_queue(&q);

    for(int i=0;i<3;i++){
        std::cout<<q.pq[i]<<",";
    }

}