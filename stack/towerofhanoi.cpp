#include<iostream>
using namespace std;

class stack{
    public:
    stack* next;
    char data;
};

// to push the element in the stack 
void push(stack ** s, char data){
    stack *new_s=new stack();
    new_s->data=data;
    new_s->next=*s;
    *s=new_s;
}
// to pop the element out of the stack
char pop(stack **s){
    if(*s==NULL){
        cout<<"No element in the stack";
        return(EOF);
    }
    else{
        stack * temp=*s;
        char tempvar=temp->data;
        *s=temp->next;
        delete(temp);
        return(tempvar);
    }    
}
// to print all the element of the stack 
void print(stack *s){
    cout<<endl;
    while(s!=NULL){
        cout<<s->data<<endl;
        s=s->next;
    }
}
//free up the heap
void removeall(stack * node){
    if(node==NULL){
        return;
    }
    removeall(node->next);
    delete(node);
}
// tower of hanoi algorithm
void towerofhanoi(int a,stack** from,stack** aux,stack** to){
    if(a==1){
       push(to,pop(from));
       return;
    }
    else{
       towerofhanoi(a-1,from,to,aux);
       push(to,pop(from));
       towerofhanoi(a-1,aux,from,to);
       
    }
}
void input(stack **a){
    push(a,'d');
    push(a,'c');
    push(a,'b');
    push(a,'a');
}
int main(){
    stack *a=NULL;
    stack *b=NULL;
    stack *c=NULL;
    input(&a);
    cout<<endl<<"stack in A";
    print(a);
    towerofhanoi(4,&a,&b,&c);
    cout<<endl<<"Stack in C";
    print(c);
    removeall(a);
    removeall(b);
    return(0);
}