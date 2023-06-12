/*
    Stack is a concept of Data strucures based on LIFO:lAST IN FIRST OUT AND IMPLEMENT THROUGH LISTS!
    3 (top) --> 2 --> 1 (bottom)
*/

#include<iostream>

class Node{
    public:
    int data;
    Node * next_node;

    Node(int data, Node * next_node = nullptr){
        this->data =data;
        this->next_node = next_node;
    }

};

class Stack{
    private: 
    Node * top; // pointer which always points to the top of stack!
    int overflow_condn = 1;
    static int count;
    public:

    Stack(){
        top = nullptr;
    }

    void push(int data){
        Node * new_node = new Node(data);
        if(count<overflow_condn){
        if(top==nullptr){
            top = new_node;
            std::cout<<"Element Pushed!"<<std::endl;
        } else{
            new_node->next_node =top;
            top = new_node;
            std::cout<<"Element Pushed!"<<std::endl;
        }
        count++;
        } else{
            std::cout<<"Stack Overflow!"<<std::endl;
        }
    }

    void display_stack(){
        if(top==nullptr){
            std::invalid_argument("Stack empty");
        } else{
            Node * dummy_ptr = top;
            while(dummy_ptr!=nullptr){
                std::cout<<dummy_ptr->data<<std::endl;
                dummy_ptr=dummy_ptr->next_node;
            }
        }
    }

    void pop(){
        if(top==nullptr){
            std::invalid_argument("Stack Empty");
        } else{
            int popped_value = top->data;
            top = top->next_node;
            std::cout<<"Popped Value"<<popped_value<<std::endl;
            count--;
        }
    }

};
int Stack::count =0;



int main()
{
    Stack myStack;
    myStack.push(2);
    myStack.push(3);
    myStack.pop();
    myStack.push(10);
    myStack.display_stack();
}