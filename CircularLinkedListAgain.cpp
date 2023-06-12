#include<iostream>
#include<stdlib.h>
using namespace std;

struct Node{
    struct Node * next;
    struct Node * prev;
    int data;
};

Node* Create_List(Node * current_node, int number_of_nodes,Node * head_node,Node * previous_node=NULL){
    int data;
    static int count=0;
    cin>>data;
    if(count<number_of_nodes){
        if(count!=number_of_nodes-1){
             // last node!
            current_node->data=data;
            Node * new_node = new Node;
            current_node->prev= previous_node;
            current_node->next = new_node;
            count++;
            Create_List(current_node->next,number_of_nodes,head_node,previous_node);
        
        } else if (count==number_of_nodes-1){
            current_node->data =data;
            current_node->prev = previous_node;
            current_node->next = head_node;
            head_node->prev=current_node;
        }
    }
    

}

void print_node (Node * head_node, int number_of_nodes){
    int count=0;
    Node * dummy_node = head_node;
    while(count<100){
        cout<<dummy_node->data<<endl;
        dummy_node = dummy_node->next;
        count++;
    }
}

int main (){
    Node * head_node = new Node;
    int number_of_nodes = 5;
    head_node = Create_List(head_node,number_of_nodes,head_node);
    print_node(head_node,number_of_nodes);
}