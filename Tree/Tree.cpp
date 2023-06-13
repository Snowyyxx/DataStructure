#include<iostream>

class Node{
    public:
    int data;
    Node * left;
    Node * right;

    Node(int data){
        this->data =data;
        left = nullptr;
        right = nullptr;
    }

    Node(){
        left = nullptr;
        right = nullptr;
    }

};

class BinarySearchTree{
    Node * root_node;

    Node * AddNode(Node * current_node, int data){
        if(current_node==nullptr){
            Node * new_node = new Node(data);
            current_node = new_node;
        } 
        else if (current_node->data<data){
            current_node->right = AddNode(current_node->right,data);
        }

        else if (current_node->data>data){
            current_node->left = AddNode(current_node->left,data);
        }

        return current_node;

    }

    void Inorder(Node * node){
        if(node!=nullptr){
            Inorder(node->left);
            std::cout<<node->data<<" ";
            Inorder(node->right);
        }
    }

    public:

    BinarySearchTree(){
        root_node = nullptr;
    }

    Node* Insert(int data){
        root_node = AddNode(root_node,data);
    }

    void InorderTravesal(){
        Inorder(root_node);
        std::cout<<std::endl;
    }


};



int main(){
    BinarySearchTree BST;
    for(int i =0;i<10;i++){
        BST.Insert(i);
    }
    BST.InorderTravesal();


}