#include<iostream>

class Node{
    public:
    int data;
    Node * left;
    Node * right;

    Node(int data){
        this->data =data;
        left = right = nullptr;
    }

};

class SplayTree{

    Node * root_node;

    Node * RotateRight(Node *x){
        Node * y = x->left;
        Node * T = y->right;

        y->right = x;
        x->left=T;

        return y;

    }

    Node * RotateLeft(Node *x){
        Node * y = x->right;
        Node * T = y->left;

        y->left = x;
        x->right=T;

        return y;

    }

    void AddNode(int data, Node * node){
        
    }

    public:
    void Insert(int data){
        root_node = AddNode(data,root_node);
    }

};

int main(){

}