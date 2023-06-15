#include<iostream>

enum Color {RED,BLACK};
// too complicated! going to start learning graphs for now hahahww
class Node{
    public:
    Color color;
    int data;
    Node * left;
    Node * right;
    Node * parent;

    Node(int data=NULL){
        this->data = data;
        left = right = parent=nullptr;
        color = RED;
    }

};

class RedBlackTree{
    Node * root_node;

    Node * RotateRight(Node * node){
        
        Node * parent = node->parent;
        Node * grand_parent = parent->parent;

        Node * T = parent->right;
        parent->left = node;
        parent->right =grand_parent;
        grand_parent->left =T;
        return parent;

    }

    Node * RotateLeft(Node * node){
        Node * parent = node->parent;
        Node * grand_parent = parent->parent;   
        Node * T = parent->left;
        parent->left = grand_parent;
        parent->right = node;
        grand_parent->right=T;
        return parent;

    }

    void FixTree(Node *&node){
        // uncle is red then change colors OR if uncle is black then rotate
        Node * uncle;
    //Finding Uncle!
        if(node->parent == node->parent->parent->left){
            uncle = node->parent->parent->right;
        }else{
            uncle = node->parent->parent->left;
        }
        //Checking if there is a red red conflict!
        if(node->parent->color==RED&&node->color==RED){
        
            if(uncle->color == RED){
                uncle->color=BLACK;
                node->parent->color=BLACK;
                if(node->parent->parent==root_node){
                }
                else if(node->parent->parent!=root_node){
                    if(node->parent->parent->color==RED){
                        node->parent->parent->color=BLACK;
                    }else {
                        node->parent->parent->color= RED;
                    }
                    FixTree(node->parent->parent);
                }
            } 

            else if(uncle->color == BLACK){
                if(node == node->parent->left && node->parent == node->parent->parent->left){
                    node = RotateRight(node);

                }else if(node == node->parent->left && node->parent == node->parent->parent->right){
                    Node * dummy_node = node->parent;
                    node->parent->parent->right = node;
                    node->right = dummy_node;
                    node = RotateLeft(node->right);
                }
                else if(node== node->parent->right && node->parent == node->parent->parent->right){
                    node= RotateLeft(node);
                }
                else if(node == node->parent->right && node->parent->parent->left==node->parent){
                    Node * dummy_node = node->parent;
                    node->parent->parent->left = node;
                    node->left = dummy_node;
                    node = RotateRight(node->left);                
                }

            }
        
        } else if(node->parent->color==BLACK){

        }
    }

    void InsertNode(Node * & node, int data){
        if(node==nullptr){
            Node * new_node = new Node(data);
            if(node==root_node){
                node = new_node;
            }else{
                new_node->parent = node->parent;
                node=new_node;
            }
        }
        else if(data<node->data){
            InsertNode(node->left,data);
        }
        else if(data>node->data){
            InsertNode(node->right,data);
        }
        else{
            std::cout<<"Duplicate Data"<<std::endl;
        }

        FixTree(node);

    }

    void InorderTraversal(Node * node){
        if(node!=nullptr){
            InorderTraversal(node->left);
            std::cout<<node->data<<",";
            InorderTraversal(node->right);
        }
    }

    public:
    RedBlackTree(){
        root_node =nullptr;
    }

    void Inorder(){
        InorderTraversal(root_node);
    }

    void Insert(int data){
        InsertNode(root_node,data);
    }
};


int main(){
    RedBlackTree tree;
    for(int =0 ;i<10;i++){
        tree.Insert(i);
    }
    tree.Inorder();
}