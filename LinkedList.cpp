#include<iostream>

struct node{
    int data;
    struct node * next;
};

void insert_node_end(struct node** q,int num){
    struct node* new_node = new node;
    new_node->data=num;
    new_node->next=NULL;

    if(*q==NULL){
        return;
    }
    struct node* temp = *q;
    while (temp->next!=NULL){
      temp=temp->next;  
    }
    temp->next=new_node;
}

void initialize_list(struct node** q, int num) {
    *q = new node;
    (*q)->data = num;
    (*q)->next = NULL;
}

void print_list_reverse(struct node* head){
    struct node * temp =head;
    if(temp){
        print_list_reverse(temp->next);
        std::cout<<temp->data;
    }    
}


void insert_node_pos(struct node**q, int num, int pos){
    if(pos==-1){
        (*q)->data=num;
        (*q)->next=NULL;
        return;
    }
    struct node * new_node = new node;
    new_node ->data = num;
    new_node->next=NULL;
    struct node * temp= *q;
    for(auto i=0;i<pos;i++){
        temp=temp->next;
    }
    new_node->next=temp->next;
    temp->next=new_node;

}

void swap_succesive_nodes(node * p){
    node *q = p->next;
    p->next = q->next;
    q->next = (q->next)->next;
    (p->next)->next = q;
}

void last_element_to_front(struct node** head){

    struct node *p=*head;
    struct node *q;
    if(*head && (*head)->next){
        while(p->next){
            q=p;
            p=p->next;
        }
        q->next=NULL;
        p->next=(*head)->next;
        *head=p;
    }

}

void reverse(struct node ** head){
    struct node *p,*c,*n;
    c=*head;
    n=NULL;

    if(*head&&(*head)->next){
        while(c->next){
            p=c->next;
            c->next=n;
            n=c;
            c=p;
        }
        *head=n;
    }

}


int main() {
    // Initialize the head of the linked list
    struct node* head = NULL;
    initialize_list(&head, 1);  // Add node with data = 1

    // Insert nodes at the end
    insert_node_end(&head, 2);
    insert_node_end(&head, 3);
    insert_node_end(&head, 4);
    insert_node_end(&head, 5);

    // Print original list in reverse
    std::cout << "Original list in reverse: ";
    print_list_reverse(head);
    std::cout << std::endl;

    // Perform swap operation starting from head (i.e., swap 1 and 2)
    swap_succesive_nodes(head);

    // Print list after first swap in reverse
    std::cout << "List after first swap in reverse: ";
    print_list_reverse(head);
    std::cout << std::endl;

    // Perform another swap operation starting from 2nd node (i.e., swap 3 and 4)
    swap_succesive_nodes(head->next->next);

    // Print list after second swap in reverse
    std::cout << "List after second swap in reverse: ";
    print_list_reverse(head);
    std::cout << std::endl;

    return 0;
}
