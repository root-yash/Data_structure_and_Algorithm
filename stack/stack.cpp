#include<iostream>
using namespace std;

class stack{
    public:
    stack* next;
    int data;
};
// to push the element in the stack 
void push(stack ** s, int data){
    stack *new_s=new stack();
    new_s->data=data;
    new_s->next=*s;
    *s=new_s;
}
// to pull the element out of the stack
void pull(stack **s){
    if(*s==NULL){
        cout<<"No element in the stack";
    }
    else{
        stack * temp=*s;
        *s=temp->next;
        delete(temp);
    }    
}
// to print all the element of the stack 
void print(stack *s){
    cout<<endl;
    while(s!=NULL){
        cout<<s->data<<' ';
        s=s->next;
    }
}
// to view the element in the top
void peek(stack *s){
    cout<<endl;
    if (s!=NULL){
        cout<<"Element on the top: "<<s->data;
    }
    else{
        cout<<"No element in the stack";
    }
}

int main(){
    stack *s=NULL;
    push(&s,2);// push 2 with the address of the pointer s 
    push(&s,3);
    push(&s,6);
    push(&s,8);
    print(s);
    pull(&s);
    push(&s,1);
    print(s);
    peek(s);
}