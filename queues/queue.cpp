#include<iostream>
using namespace std;

class Node{
    public:
    Node * next;
    int data;
};

Node *assign(int d){                                          // assign a node in a heap with the input data  
    Node *new_node= new Node();
    new_node->data=d;
    new_node->next=NULL;
    return new_node;
}

void enqueue(int d, Node ** front,Node ** rear){             // Insert the node in the queue 
    Node *new_node= assign(d);
    if(*rear==NULL){
        *front=*rear=new_node;
        return;
    }
    (*rear)->next=new_node;
    *rear=new_node;
}
 
void dequeue(Node ** front,Node ** rear){                    // remove node from the front of the queue 
    Node *temp = *front;
    if(*front==NULL){
        cout<<"Empty Queue";
        return;
    }
    *front=(*front)->next;
    if (*front==NULL){
        *rear==NULL;
    }
    delete(temp);
}
void contains(Node *front,Node *rear){                       // display the node in the queue
    cout<<"\nIt Contains:";
    while(front!=rear->next){
        cout<<front->data<<" ";
        front=front->next;
    }
}
int main(){
    Node *front=NULL;
    Node *rear=NULL;
    enqueue(2,&front,&rear);
    enqueue(3,&front,&rear);
    enqueue(4,&front,&rear);
    dequeue(&front,&rear);
    enqueue(5,&front,&rear);
    contains(front,rear);
    cout<<"\nPeek: "<<front->data;
    return(0);
}