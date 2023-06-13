#include<iostream>
#include <chrono>


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
            std::cout<<node->data<<",";
            Inorder(node->right);
        }
    }

    int SearchTree(Node * node, int data){
        static int count =0;
        if(data!=node->data){
            if(data < node->data){
                count++;
                return SearchTree(node->left,data);
            }
            else if(data > node->data){
                count++;
                return SearchTree(node->right,data);
            }
        }
        else if(data==node->data){
            std::cout<<"Tree Data Found:"<<node->data;
            return count;
        }
        
    }

    public:

    BinarySearchTree(){
        root_node = nullptr;
    }

    void Insert(int data){
        root_node = AddNode(root_node,data);
    }

    void InorderTravesal(){
        Inorder(root_node);
    }

    int Search(int data){
        return SearchTree(root_node,data);
    }

};

int BinarySearch(int array[], int data,int length,int start_index,int end_index){
    int middle_index = (start_index + end_index)/2;
    
    if(data == array[middle_index]){
        std::cout<<"Array Data Found:"<<array[middle_index]<<std::endl;
        return middle_index;
    }

    else if(data < array[middle_index]){
        return BinarySearch(array,data,length,start_index,middle_index-1);
    }
    
    else if(data > array[middle_index]){
        return BinarySearch(array,data,length,middle_index+1,end_index);
    }

   
  

}

int main(){
    std::cout<<std::endl;
    int length =20000;
    int array[length];
    BinarySearchTree BST;

    for(int i =0;i<length;i++){
        array[i]=2*i+1;
    }

    for(int j =0;j<length;j++){
        BST.Insert(array[j]);
    }
    int target_index = 1999;
    std::cout<<"Target Element:"<<array[target_index]<<" which is at Index: "<<target_index<<std::endl;
    //BST.InorderTravesal();
    auto start = std::chrono::high_resolution_clock::now();
    std::cout<<std::endl<<"Node Number: "<<BST.Search(array[target_index]);
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout <<std::endl <<"Execution time for TREE: " << duration.count() << " microseconds" << std::endl;

    std::cout<<std::endl;

    start = std::chrono::high_resolution_clock::now();
    std::cout<<"Index Number: "<<BinarySearch(array,array[target_index],length,0,length-1);
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout <<std::endl <<"Execution time for BINARY SEARCH: " << duration.count() << " microseconds" << std::endl;

}