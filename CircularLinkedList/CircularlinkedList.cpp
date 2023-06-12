#include<iostream>
#include<stdlib.h>


struct Node{
    Node * next=NULL;
    Node * previous=NULL;
    int data;
};

void create_list(int number_of_nodes,Node * head_node,Node*previous_node=NULL);
void print_list(Node* current_node, int number_of_nodes);

int main(){
    Node * head_node = new Node;
    int number_of_nodes = 5;
    create_list(head_node,number_of_nodes,head_node);
    print_list(head_node,number_of_nodes);
}

void create_list(int number_of_nodes,Node * head_node, Node*previous_node){
    static int count = 0;
    int data;
    Node * current_node = new Node;
    
    current_node = head_node;

    if(count < number_of_nodes){
        std::cout<<"Enter Data:";
        std::cin>>data;
        std::cout<<std::endl<<"Value of count:"<<count<<std::endl;
        current_node->data=data;
        if(count == number_of_nodes-1){
            head_node->previous = current_node;
            current_node->next = head_node;
      } else{
            Node * new_node = new Node;
            current_node->next = new_node;
        }
        count++;
        create_list(current_node->next,number_of_nodes,current_node);

    }
}

void print_list(Node* current_node, int number_of_nodes){
    int count=0;
    Node * dummy_node = current_node->next;
    while(count< 5){
        std::cout<<dummy_node->data<<std::endl;
        dummy_node = dummy_node->next;
        count++;
    }
}