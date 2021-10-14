#include<iostream>
using namespace std;
class StackUsingArray{
public:
    int st[20];
    int top,s=20;
    StackUsingArray(){
        top=-1;
    }
    void push(int item);
    void clearStack();
    void pop();
    bool isEmpty();
    int sizeOfStack();
    int topElement();
    void display();

};

bool StackUsingArray::isEmpty(){
    if(top==-1){
        return true;
    }
    return false;
}

void StackUsingArray::push(int item){
    if(top==(s-1)){
        cout<<"Stack Overflow"<<endl;
    }
    else{
        st[++top]=item;
    }
}

void StackUsingArray::pop(){
    if(top==-1){
        cout<<"Stack Underflow"<<endl;
    }
    else{
        int item=st[top];
        top--;
        cout<<"Element pop : "<<item<<endl;
    }
}

void StackUsingArray::clearStack(){
    while(top!=0){
        pop();
    }
    cout<<"Element pop : "<<st[top]<<endl;
    top--;
    cout<<"Stack emptied"<<endl;
}

int StackUsingArray::sizeOfStack(){
    return (top+1);
}

int StackUsingArray::topElement(){
    return st[top];
}

void StackUsingArray::display(){
    int n=top;
    if(n==-1){
        cout<<"Stack is empty"<<endl;
    }
    else{
        cout<<"Element in stack: ";
        while(n!=-1){
            cout<<st[n]<<" ";
            n--;
        }
        cout<<endl;
    }
}

int main(){
    StackUsingArray ob;
    if(ob.isEmpty()){
        cout<<"Stack is empty.Enter number of elements to enter.";
        int i,n;
        cin>>i;
        for(int j=0;j<i;j++){
            cin>>n;
            ob.push(n);
        }
    }
    char ch;
    do{
        cout<<"Enter 1 to display the Stack."<<endl;
        cout<<"Enter 2 to push element in stack."<<endl;
        cout<<"Enter 3 to pop element from the stack."<<endl;
        cout<<"Enter 4 to know size of stack."<<endl;
        cout<<"Enter 5 to know the top element in stack."<<endl;
        cout<<"Enter 6 to check if stack is empty."<<endl;
        cout<<"Enter 7 to clear stack."<<endl;
        cout<<"Enter your choice: ";
        int choice;
        cin>>choice;
        int num;
        switch(choice){
        case 1:
            cout<<"Elements in Stack:"<<endl;
            ob.display();
            break;
        case 2:
            cout<<"Enter element to push: ";
            cin>>num;
            ob.push(num);
            cout<<"Element pushed"<<endl;
            break;
        case 3:
            ob.pop();
            break;
        case 4:
            cout<<"Size of stack:"<<ob.sizeOfStack()<<endl;
            break;
        case 5:
            cout<<"Element at top of stack:"<<ob.topElement()<<endl;
            break;
        case 6:
            if(ob.isEmpty()){
                cout<<"Stack is empty"<<endl;
            }
            else{
                cout<<"Stack is not empty"<<endl;
            }
            break;
        case 7:
            ob.clearStack();
            break;
        default:
            cout<<"Invalid choice";
        }
        cout<<"Enter y to continue:";
        cin>>ch;
        cout<<endl;
    }while(ch=='y'||ch=='Y');
    cout<<"Program ended";
    return 0;
}
