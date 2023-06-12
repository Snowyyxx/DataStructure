/*
FIRST IN FIRST OUT
stores item from one end and removes items from the other end!

*/

#include<iostream>

class Node{
    public:
    Node * next;
    int data;
    Node(int data){
        this->data = data;
        next= nullptr;
    }
};

class Queue{

    Node * front;
    Node * back;

    public:
    
    Queue(){
        front = nullptr;
        back = nullptr;
    }

    void enqueue(int data){
        Node * new_node = new Node (data);
        if(front==nullptr && back==nullptr){
            front = new_node;
            back = new_node;
            std::cout<<"element queued"<<std::endl;
        } else if(front!=nullptr && back!=nullptr){
            back->next = new_node;
            back = new_node;
            std::cout<<"element queued"<<std::endl;
        }
    }

    void dequeue(){
        if(front == nullptr){
            throw std::invalid_argument("queue empty");
        } else {
            std::cout<<"element dequeued"<<front->data;
            front = front->next;
        }
    }

    void DisplayListFrontToBack(){
        Node * temp = front;
        while(temp!=nullptr){
            std::cout<<temp->data<<std::endl;
            temp = temp->next;
        }
    }

};


int main()
{
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.dequeue();
    q.enqueue(3);
    q.DisplayListFrontToBack();
}