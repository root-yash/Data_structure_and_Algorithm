#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
};

//input nodes
void input(Node** head, int in_data){
    Node* new_node= new Node();
    new_node->data=in_data;
    new_node->next=*head;
    *head=new_node; 
}
//liner remove 
void remove(Node** node, int in_data){
    Node *prev;
    Node *head=*node;
    while(head!=NULL){
        prev=head;
        head=head->next;
        if(head->data==in_data){
            prev->next=head->next;
            delete(head);
            break;
        }
        cout<<"No value like this exist";
    }

}
//recursive remove 
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
// printing value 
void print(Node *node){
    while(node!=NULL){
        cout<<node->data;
        node=node->next;
    }
}
//recursive delete all list
void removeall(Node * node){
    if(node==NULL){
        return;
    }
    removeall(node->next);
    delete(node);
}
int main(){
    Node* head=NULL;
    input(&head,2);
    input(&head,3);
    input(&head,7);
    input(&head,5);
    rr(head,3);
    print(head);
    removeall(head);
    return(0);
}