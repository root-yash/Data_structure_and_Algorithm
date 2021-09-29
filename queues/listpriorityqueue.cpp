#include<iostream>
using namespace std;

class Node{
    public:
    Node * next;
    int priority;
    int data;
};

Node *assign(int d,int priority){                                          // assign a node in a heap with the input data  
    Node *new_node= new Node();
    new_node->data=d;
    new_node->priority=priority;
    new_node->next=NULL;
    return new_node;
}
// input the data
void push(int d,int priority,Node ** head){             // Insert the node in the queue 
    Node *new_node= assign(d,priority);
    Node * temp = *head;
    if(temp == NULL){
        *head=new_node;
        return;
    }
    if((*head)->priority>priority){
        new_node->next=*head;
        *head=new_node;
    }
    else{
        Node *t;
        while(temp!=NULL && temp->priority<priority){
            t = temp;
            temp=temp->next;
            if (temp==NULL){
                t->next=new_node;
                return;   
            }
            if(temp->priority>priority){
                new_node->next=temp;
                t->next=new_node;
            }

        }
    }
    
}

// printing value 
void print(Node *node){
    while(node!=NULL){
        cout<<node->data;
        node=node->next;
    }
}
// remove the element
void rr(Node*& head, int in_data){
    if (head==NULL){
        cout<<"NO Value like that exist";
        return;
    }
    if (head->data==in_data){
        Node * temp=head;
        head=head->next;
        delete(temp);
        return;
    }
    rr(head->next,in_data);
}
int main(){
    Node *head=NULL;
    push(1,2,&head);
    push(2,1,&head);
    push(4,5,&head);
    push(8,4,&head);
    rr(head,8);
    print(head);
    return(0);
}