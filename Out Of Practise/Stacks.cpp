#include<iostream>

class Node{
    public:
    Node * next_node;
    int key;

    Node(int key){
        this->key = key;
        next_node = nullptr;
    }
};

class Stack{
    Node * top;
    static int count;
    int StackOverFlowLimit;
    int StackUnderFlowLimit;
    public:

    Stack(int StackOverFlowLimit, int StackUnderFlowLimit){
        top = nullptr;
        this->StackOverFlowLimit = StackOverFlowLimit;
        this->StackUnderFlowLimit = StackUnderFlowLimit;
    }

    void Push(int key){
        Node * new_node = new Node(key);
        if(top==nullptr){
            if(count<=StackOverFlowLimit){
                top = new_node;
                count++;
            }
        } else {
        
            if(count<=StackOverFlowLimit){
                new_node->next_node = top;
                top = new_node;
                count++;
            }
        
        }
    }

    void Pop(){
        if(count-1>=StackUnderFlowLimit){
            Node * temp_node = top;
            top = top->next_node;
            delete(temp_node);
            count--;
        }
    }

    void DisplayStack(){
        Node * dummy_node = top;
        while(dummy_node!=nullptr){
            std::cout<<dummy_node->key<<",";
            dummy_node = dummy_node->next_node;
        }
    }

};

int Stack::count =0;

int main(){
 Stack s(5, 0);  // Stack with max size 5 and min size 0

    s.Push(10);
    s.Push(20);
    s.Push(30);
    s.DisplayStack(); // Should print 30,20,10,

    s.Pop();
    s.DisplayStack(); // Should print 20,10,

    return 0;

}