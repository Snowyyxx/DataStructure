#include<iostream>

class Node{
    public:
    int data;
    int height;
    Node * left;
    Node * right;

    Node(int data){
        this->data = data;
        left = right = nullptr;
    }
};

class AVLTree{
    Node * root_node;
    int Calculate_Height(Node * node){
        if(node == nullptr){
            return 0;
        }
        return 1+ std::max(Calculate_Height(node->left),Calculate_Height(node->right));
    }

    int Balancing_Factor(Node * node){
        return Calculate_Height(node->left)-Calculate_Height(node->right);
    }

    Node *  Left_Rotation(Node * x){
        Node * y = x->right;
        Node * T = y->left;

        //Rotation!
        y->left = x;
        x->right = T;

        // UpdatingHeight
        y->height = Calculate_Height(y);
        x->height = Calculate_Height(x);

        return y;
    }

    Node * Right_Rotation(Node * x){
        Node * y = x->left;
        Node * T = y->right;
        //Rotation!
        y->right = x;
        x->left = T;

        // UpdatingHeight
        y->height = Calculate_Height(y);
        x->height = Calculate_Height(x);

        return y;

    }

    void Insert_Node(Node * & node, int data){
        if(node==nullptr){
            node = new Node(data);
        }
        else if(data<node->data){
            Insert_Node(node->left,data);
        }
        else if(data>node->data){
            Insert_Node(node->right,data);
        }
        else if (data==node->data){
            std::cout<<"Duplicate Value not allowed!"<<std::endl;
        }
        node->height = Calculate_Height(node);
        int balance_factor = Balancing_Factor(node);

        if(balance_factor>1 && node->left->data>data){
            // left-left!
            node = Right_Rotation(node);
        }
        else if(balance_factor>1 && node->left->data<data){
            // left-right!
            node->left = Left_Rotation(node->left);
            node = Right_Rotation(node);
        }
        else if(balance_factor<-1 && node->right->data>data){
            // right-left!
            node->right = Right_Rotation(node->right);
            node = Left_Rotation(node);
        }
        else if(balance_factor<-1 && node->right->data<data){
            // right-right!
            node = Left_Rotation(node);
        }


    }

    void Inorder(Node * node){
        if(node!=nullptr){
            Inorder(node->left);
            std::cout<<node->data<<", ";
            Inorder(node->right);
        }
    }


    public:

    AVLTree(){
        root_node = nullptr;
    }

    void Insert(int data){
        Insert_Node(root_node,data);
    }

    void InorderTrasversal(){
        Inorder(root_node);
    }

};

int main(){
AVLTree tree;
for (int i = 1; i <= 10000; i++) {
    tree.Insert(i);
}
// Perform inorder traversal or any other required operations
tree.InorderTrasversal();

} 