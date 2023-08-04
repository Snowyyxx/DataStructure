#include<iostream>

class Node{
    public:
    Node * left;
    Node * right;
    int key;

    Node(int key){
        this->key = key;
        left = right = nullptr;
    }

    Node(){

    }
};

class AVLTree{
    Node * root_node;

    Node *  RotateLeft(Node * x){
        Node * y = x->right;
        Node * z = y->left;

        y->left = x;
        x->right = z;
        return y;
    }

    Node * RotateRight(Node * x){
        Node * y = x->left;
        Node * z = y->right;
        y->right = x;
        x->left = z;
        return y;

    }

    int CalculateHeight(Node * node){
        
        if(node==nullptr){
            return 0;
        }
        return 1+std::max(CalculateHeight(node->left),CalculateHeight(node->right));

    }

    public:



};


int main(){

}