#include<iostream>

class Node{
    public:
    int data;
    Node * next;
    Node(int data){
        this->data =data;
        next =nullptr;
    }
};

class Stack{
    Node * top;
    public:

    void Push(int data){
        Node * new_node = new Node (data);
        if(top == nullptr){
            top = new_node;
            std::cout<<"Data Inserted in Stack"<<std::endl;
        }
        else{
            new_node->next = top;
            top = new_node;
        }
    }

    void Pop(){
        std::cout<<"Element Popped:"<<top->data<<std::endl;
        top = top->next;
    }




};


int main(){


}