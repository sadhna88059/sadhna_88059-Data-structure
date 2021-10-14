#include<iostream>
using namespace std;
class Node
{
public:
    int data;
    Node* next;
    Node(int n){
        this->data=n;
        this->next=NULL;
    }
};
class CircularSingleLinkedList
{
public:
    Node* tail, *temp, *ptr;
    CircularSingleLinkedList(){
        tail=NULL;
    }
    void insertAtStart(int num);
    void insertInMid(int num,int index);
    void insertAtEnd(int num);
    void deleteFromStart();
    void deleteFromMid(int index);
    void deleteFromEnd();
    void searchNumber(int num);
    void display();
};

void CircularSingleLinkedList::insertAtStart(int num){
    temp=new Node(num);
    if(tail==NULL){
        tail=temp;
        tail->next=tail;
    }
    else{
        temp->next = tail->next;
        tail->next=temp;
    }
    temp=NULL;
}

void CircularSingleLinkedList::insertAtEnd(int num){
    temp=new Node(num);
    if(tail==NULL){
        tail=temp;
        tail->next=temp;
    }
    else{
        temp->next=tail->next;
        tail->next=temp;
    }
    tail=temp;
}

void CircularSingleLinkedList::insertInMid(int num, int index){
    temp=new Node(num);
    ptr=tail;
    int count=0;
    while(count!=index-1){
        ptr=ptr->next;
        count++;
    }
    temp->next=ptr->next;
    ptr->next=temp;
    temp=ptr=NULL;
}

void CircularSingleLinkedList::deleteFromEnd(){
    temp=tail;
    while(temp->next!=tail){
        temp=temp->next;
    }
    temp->next=tail->next;
    delete(tail);
    tail=temp;
}

void CircularSingleLinkedList::deleteFromStart(){
    temp=tail->next;
    tail->next=temp->next;
    delete(temp);
}

void CircularSingleLinkedList::deleteFromMid(int num){
    temp=tail->next;
    while(temp->next->data!=num){
        temp=temp->next;
    }
    ptr=temp->next;
    temp->next=ptr->next;
    delete(ptr);
}

void CircularSingleLinkedList::searchNumber(int num){
    temp=tail->next;
    int count=1;bool flag=false;
    while(temp!=tail){
        if(temp->data==num){
            flag=true;
            break;
        }
        temp=temp->next;
        count++;
    }
    if(tail->data==num){
        flag=true;
    }
    if(flag){
        cout<<num<<" Number found at position: "<<count<<endl;
    }
    else
        cout<<num<<" Number not found!!!"<<endl;
}

void CircularSingleLinkedList::display(){
    if(tail==NULL){
        cout<<"!!!! List is empty !!!"<<endl;
    }
    else{
        temp=tail->next;
        while(temp!=tail){
            cout<< temp->data<<"--->";
            temp=temp->next;
        }
        cout<<tail->data<<endl;
        temp=NULL;
    }
}
int main(){
    CircularSingleLinkedList ob,ob1,ob2,ob3;char ch;
    do{
        cout<<"Enter 1 to display the Circular Single Linked List."<<endl;
        cout<<"Enter 2 to insert element at start."<<endl;
        cout<<"Enter 3 to insert element in the end."<<endl;
        cout<<"Enter 4 to insert element in the middle."<<endl;
        cout<<"Enter 5 to delete element at start."<<endl;
        cout<<"Enter 6 to delete element in the end."<<endl;
        cout<<"Enter 7 to delete element in the middle."<<endl;
        cout<<"Enter 8 to search element in the Linked List."<<endl;
        cout<<"Enter your choice: ";
        int choice;
        cin>>choice;
        int num,index;
        switch(choice){
        case 1:
            cout<<"Single Linked List:"<<endl;
            ob.display();
            break;
        case 2:
            cout<<"Enter element to insert: ";
            cin>>num;
            ob.insertAtStart(num);
            cout<<"Element inserted"<<endl;
            break;
        case 3:
            cout<<"Enter element to insert: ";
            cin>>num;
            ob.insertAtEnd(num);
            cout<<"Element inserted"<<endl;
            break;
        case 4:
            cout<<"Enter element to insert: ";
            cin>>num;
            cout<<"Enter position at which to insert: ";
            cin>>index;
            ob.insertInMid(num,index);
            cout<<"Element inserted at index "<<index<<endl;
            break;
        case 5:
            ob.deleteFromStart();
            cout<<"Element deleted"<<endl;
            break;
        case 6:
            ob.deleteFromEnd();
            cout<<"Element deleted"<<endl;
            break;
        case 7:
            cout<<"Enter element to delete: ";
            cin>>num;
            ob.deleteFromMid(num);
            cout<<"Element deleted"<<endl;
            break;
        case 8:
            cout<<"Enter element to check: ";
            cin>>num;
            ob.searchNumber(num);
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

