#include<iostream>
using namespace std;
class Node
{
public:
    int data;
    Node* next;
    Node* prev;
    Node(int n){
        this->data=n;
        this->next=NULL;
        this->prev=NULL;
    }
};
class DoubleLinkedList
{
public:
    Node* head, *temp, *ptr, *temp1;
    DoubleLinkedList(){
        head=NULL;
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
void DoubleLinkedList::insertAtStart(int num){
    temp=new Node(num);
    if(head!=NULL){
        temp->next = head;
        head->prev=temp;
    }
    head=temp;
    temp=NULL;
}

void DoubleLinkedList::insertAtEnd(int num){
    temp=new Node(num);
    ptr=head;
    while(ptr->next!=NULL){
        ptr=ptr->next;
    }
    ptr->next=temp;
    temp->prev=ptr;
    temp=ptr=NULL;
}

void DoubleLinkedList::insertInMid(int num, int index){
    temp=new Node(num);
    ptr=head;
    int count=1;
    while(count!=index-1){
        ptr=ptr->next;
        count++;
    }
    temp->next=ptr->next;
    ptr->next->prev=temp;
    ptr->next=temp;
    temp->prev=ptr;
    temp=ptr=NULL;
}

void DoubleLinkedList::deleteFromEnd(){
    temp=head;
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    delete(temp->next);
    temp->next=NULL;

}

void DoubleLinkedList::deleteFromStart(){
    temp=head;
    head=temp->next;
    head->prev=NULL;
    delete(temp);
}

void DoubleLinkedList::deleteFromMid(int num){
    temp=head;
    while(temp->next->data!=num){
        temp=temp->next;
    }
    ptr=temp->next;
    temp1=ptr->next;
    temp->next=temp1;
    temp1->prev=temp;
    delete(ptr);
}

void DoubleLinkedList::searchNumber(int num){
    temp=head;
    int count=1;bool flag=false;
    while(temp!=NULL){
        if(temp->data==num){
            flag=true;
            break;
        }
        temp=temp->next;
        count++;
    }
    if(flag){
        cout<<num<<" Number found at position: "<<count<<endl;
    }
    else
        cout<<num<<" Number not found!!!"<<endl;
}

void DoubleLinkedList::display(){
    temp=head;
    if(head==NULL){
        cout<<"!!!! List is empty !!!"<<endl;
    }
    else{
        while(temp!=NULL){
            cout<< temp->data<<"--->";
            temp=temp->next;
        }
        cout<<"NULL"<<endl;
    }
    temp=NULL;
}
int main(){
    DoubleLinkedList ob,ob1,ob2,ob3;char ch;
    do{
        cout<<"Enter 1 to display the Double Linked List."<<endl;
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
            cout<<"Double Linked List:"<<endl;
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
