#include<iostream>
//Balancing Factor (for every node is different) = height of left subtree - height of right subtree = {-1,0,1} are allowed

class Node{
    public:
    int data;
    Node * left;
    Node * right;

    Node(int data){
        this->data =data;
        left = right =nullptr;
    }
    Node(){
        left = right =nullptr;
    }

};

class AVLTree{
    private:
    Node * root_node;
    void InsertNode(int data, Node *& node){ // reference to a pointer of a node!
        if(node == nullptr){
            node = new Node(data);
        }
        else if (data < node->data){
            InsertNode(data,node->left);
        }
        else if(data > node->data){
            InsertNode(data,node->right);
        }
    }

    void InorderTraversal (Node * node){
        if(node!=nullptr){
            InorderTraversal(node->left);
            std::cout<<node->data<<",";
            InorderTraversal(node->right);
        }
    }

    void PreorderTraversal(Node * node){
        static int count = 0 ;
        Node * dummy_node;
        if(count ==0 ){
            dummy_node = node;
            std::cout<<node->data<<",";
            count++;
            PreorderTraversal(node->left);
        }

        else if(node!=dummy_node&&node!=nullptr){
            PreorderTraversal(node->left);
            std::cout<<node->data<<",";
            PreorderTraversal(node->right);
        }

    }

    public:

    void Insert(int data){
        InsertNode(data,root_node);
    }

    void Inorder(){
        InorderTraversal(root_node);
        std::cout<<std::endl;
    }

    AVLTree(){
        root_node = nullptr;
    }

    void Preorder(){
        PreorderTraversal(root_node);
        std::cout<<std::endl;
    }

};


int main (){
    AVLTree tree;
    for(int i =0;i<10;i++){
        tree.Insert(i);
    }
    tree.Inorder();
    tree.Preorder();
}