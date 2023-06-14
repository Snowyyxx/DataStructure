#include<iostream>

class Node{
    public:
    int key;
    Node * left;
    Node * right;
    int height;

    Node(){
        left = right = nullptr;
    }

    Node(int key){
        this->key =key;
        left = right = nullptr;
    }
    
};

class  AVLTree{
    Node * root_node;
    
    int CalculateHeight(Node * node){
        
        if(node==nullptr){
            return 0;
        }
        return 1+std::max(CalculateHeight(node->left),CalculateHeight(node->right));

    }

    int BalancingFactor(Node * node){
        return CalculateHeight(node->left)-CalculateHeight(node->right);
    }
    
    Node * rotateRight(Node *x){
        Node * y = x->left;
        Node * z = y->left;
        Node * T2 = y->right;
        Node * T3 = x->right;
        //y->left = z;
        y->right = x;
        x->left =T2;
        //x->right =T3;

        y->height = CalculateHeight(y);
        x->height = CalculateHeight(x);

        return y;

    }

    Node * rotateLeft(Node * x){
            
        Node* y = x->right;
        Node* z = y->right;
        Node * T2 = y->left;

        //Rotation:
        y->left =x;
        y->right = z;
        x->right=T2;

        // Update heights
        x->height = CalculateHeight(x);
        y->height = CalculateHeight(y);

        return y;
    }
    

    Node * Create_Node(Node * node, int key){
        if(node == nullptr){
            Node * new_node = new Node(key);
            node = new_node;
            return node;
        }
        else if (key < node->key){
            node->left =  Create_Node(node->left,key);
        }
        else if(key > node->key){
            node->right= Create_Node(node->right,key);
        }
        else if(key == node->key){
            std::cout<<"duplicte keys not allowed in BST!"<<std::endl;
            return node;
        }
        // update height of ancestor node!
        node->height = CalculateHeight(node);
        
        // check the balance factor and do roations if needed!
        int balance_factor = BalancingFactor(node);

        // bf = {-1,0,1}
        // 4 Rotations : left-left , right-right ,left-right , right-left
        //left-left:
        if(balance_factor>1 && key<node->left->key) // balanc factor cant be greater than 1 when only 2 nodes in AVL! 
        {
            //      A                B
            //     / \              / \
            //    B   T3    ->     C   A
            //   / \                  / \
            //  C   T2               T2  T3
            return rotateRight(node);

        }
        // left-right
        else if (balance_factor>1 && key>node->left->key){

//      x                x                z
//     / \              / \              / \
//    y   T2    ->     z   T2    ->     y   x
//   / \              /               /     \
//  T3  z            y              T3       T2
//                  /
//                 T3      
        node->left = rotateLeft(node->left);
        node = rotateRight(node);

        }
        // right-right
        else if(balance_factor<-1 && key>node->right->key){
    //   A                B
    //  / \              / \
    // T1  B     ->     A   C
    //    / \          / \
    //   T2  C        T1  T2
        node = rotateLeft(node);

        }
        //right-left;
        else if(balance_factor<-1 && key<node->right->key){
            node->right = rotateRight(node->right);
            node = rotateLeft(node);
        }

        return node;
    }

    void Inorder(Node * node){
        if(node!=nullptr){
            Inorder(node->left);
            std::cout<<node->key<<", ";
            Inorder(node->right);
        }
    }

    public:
    void Insert(int key){
        root_node  = Create_Node(root_node,key);
    }

    void InorderTransversal(){
        Inorder(root_node);
    }
    AVLTree(){
        root_node = nullptr;
    }


};


int main(){
AVLTree tree;
tree.Insert(5);
tree.Insert(3);
tree.Insert(5);  // Duplicate key
tree.Insert(2);
tree.InorderTransversal();  // Expected output: 2, 3, 5
}