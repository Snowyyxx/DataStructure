#include<iostream>
using namespace std;
// circular linked list!


struct node{
    struct node * next_node;
    struct node * prev_node;
    int value;
};

node * create_list(node * current_node){
    int data;
    node * next_node;
    cin>>data;
    cout<<endl;
    static int count =0;
    if(count==0){
        current_node->prev_node=NULL;
        current_node->value = data;
        current_node->next_node=next_node;
        create_list(next_node);
    }
}

int main (){
    node * head_node;
    int number_nodes = 5;
    int i =0;
    while(i<number_nodes){

        head_node= create_list(head_node);
    }

}