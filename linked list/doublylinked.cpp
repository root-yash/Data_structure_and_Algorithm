#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node * next;
    Node * previous;
};
// taking input for the nodes 
void input(Node **head,int in_data){
    Node* node= new Node();
    Node* temp= *head;
    node->data=in_data;
    node->next=*head;
    node->previous=NULL;
    if(temp!=NULL)
    {
        temp->previous=node;
    }
    *head=node;
}
//remove one element from the node 
void removeone(Node *head, int r_data){
    while(head!=NULL){
        if(head->data==r_data){
            (head->previous)->next=head->next;
            delete(head);
            break;
        }
        head=head->next;
    }
}
//remove one element from the node recursively 
void rr(Node *head,int r_data){
    if(head->data==r_data){
        (head->previous)->next=head->next;
        delete(head);
        return;
    }
    rr(head->next,r_data);
}
// print the linked list
void print(Node *head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
}

int main(){

    Node *head =NULL;
    input(&head,2);
    input(&head,1);
    input(&head,3);
    input(&head,7);
    input(&head,4);
    input(&head,5);
    print(head);
    cout<<endl;
    removeone(head,3);
    rr(head,4);
    print(head);
    return(0);
}