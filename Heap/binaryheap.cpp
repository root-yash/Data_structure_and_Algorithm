// this program construct dynamic min max heap 

#include<iostream>
using namespace std;

void swap(int* a,int* b);
// class heap containing all function and data
class heap{
    int * loc;                         //pointer to point to array
    int size=3;                       // size of the array
    int layer=2;                     //height of the heap
    int current=0;                   // the no of element present in the array
    bool (*func)(int,int);          // store if the the user wants to do mean or max heap
    public:
    heap(bool(*func)(int,int));               //constructor to initialize the dynamic array of size 3 and taking the min or max function
    void incsize();                           // to increase size of the dynamic array
    int parent(int i){ return (i-1)/2;}       //return parent index
    int lchild(int i){ return((2*i)+1);}      //return left child index
    int rchild(int i){ return((2*i)+2);}      //return right child index
    void insert(int data);                    // insert data in the heap
    void delete_root();                       // delete the root of the heap
    void heapify(int i);                      // heap variance 
    void peek();                              // view root element
};

heap::heap(bool (*func)(int,int)){
    loc=new int[3];
    this->func=func;
}
void heap::incsize(){
    size=size+2^(layer);
    layer++;
    int *temp=new int[size];
    for(int i=0;i<current;i++){
        temp[i]=loc[i];
    }
    delete(loc);
    loc=temp;
}
void heap::insert(int data){
    if(current>=size){
        incsize();
    }
    int i=current;
    current++;
    loc[i]=data;
    while(i!=0 && func(loc[parent(i)],loc[i])){
        swap(&loc[parent(i)],&loc[i]);
        i=parent(i);
    }
}

void heap::delete_root(){
    if (current<=1){
        current--;
        return;
    }
    loc[0]=loc[current-1];
    current--;
    heapify(0);    
}

void heap::heapify(int i){
    int l, r;
    l=lchild(i);
    r=rchild(i);
    if(func(loc[i],loc[r]) || func(loc[i],loc[l])){
        if(func(loc[r],loc[l])){
            swap(&loc[i],&loc[l]);
            heapify(l);
        }
        else{
            swap(&loc[i],&loc[r]);
            heapify(r);
        }
    }
    else{
        return;
    }
}
void heap::peek(){
    cout<<"Element at root: "<<loc[0]<<endl;
}
void swap(int *a, int *b){                                    
    int temp=*a;
    *a=*b;
    *b=temp;   
}
bool min(int a,int b){                                       //min heap function
    if (a>b){
        return(true);
    }
    else{
        return(false);
    }
}
bool max(int a,int b){                                      //max heap function
    if (a<b){
        return(true);
    }
    else{
        return(false);
    }
}
int main(){
    heap h(min);
    cout<<"MIN Heap:\n";                                         //sent max or min at time of object initialization to produce that kind of heap
    h.insert(1);
    h.insert(3);
    h.insert(8);
    h.peek();
    h.insert(9);
    h.insert(2);
    h.peek();
    h.insert(11);
    h.insert(56);
    h.delete_root();
    h.peek();
    heap h1(max);
    cout<<"MAX Heap:\n"; 
    h1.insert(1);
    h1.insert(3);
    h1.insert(8);
    h1.peek();
    h1.insert(9);
    h1.insert(2);
    h1.peek();
    h1.insert(11);
    h1.insert(56);
    h1.delete_root();
    h1.peek();
    return(0);

}