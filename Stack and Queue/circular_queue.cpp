#include<iostream>
#define MAX 10

struct Q{
    int pq[MAX];
    int front;
    int rear;
};

void init(struct Q * q){
    q->front = -1;
    q->rear = -1;
}

void enqueue(struct Q * q, int x){
    if(q->front==0 && q->rear == MAX-1){
        std::cout<<"Overflow"<<std::endl;
        return;
    }

    if(q->rear == MAX-1 && q->front !=0){
        q->rear = 0;
    }
    else{
        q->rear = q->rear +1;
    }
    q->pq[q->rear] = x;
    if(q->front ==-1){
        q->front = 0;
    }
    
}

int dequeue(struct Q * q){
    if(q->front == -1){
        std::cout<<"underflow"<<std::endl;
        return NULL;
    }

    int item  =q->pq[q->front];
    if(q->front == MAX-1){
        q->front = 0;
    }
    else{
        q->front=q->front +1;
    }
    return item;
}

int size(struct Q* q){
    int count =0;
    if(q->rear<q->front){
        for(auto i =0;i<=q->rear;i++){
            count++;
        }
        for(auto j =q->rear;j<q->front;j++){
            count++;
        }
    }
    else if(q->rear>q->front){
        for(auto k=q->front;k<=q->rear;k++){
            count++;
        }
    }
    return count;
}

int main()

{

}