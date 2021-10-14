#include<iostream>
using namespace std;
class Node
{
public:
    int data;
    Node* next;
};
class SingleLinkedList
{
public:
    Node* head, *tail, *temp, *ptr, *current;
    SingleLinkedList(){
        head=NULL;
    }
    void insertAtStart(int num);
    void insertInMid(int num,int index);
    void insertAtEnd(int num);
    void deleteFromStart();
    void deleteFromMid(int index);
    void deleteFromEnd();
    void reverseLinkedList();
    void searchNumber(int num);
    void display();
    SingleLinkedList operator+(SingleLinkedList &ob);
};
void SingleLinkedList::insertAtStart(int num){
    temp=new Node();
    temp->data = num;
    temp->next = NULL;
    if(head==0){
        head=tail=temp;
    }
    else{
        temp->next = head;
        head=temp;
    }
    temp=NULL;
}

void SingleLinkedList::insertAtEnd(int num){
    temp=new Node();
    temp->data = num;
    temp->next = NULL;
    ptr=head;
    while(ptr->next!=NULL){
        ptr=ptr->next;
    }
    ptr->next=temp;
    temp=ptr=NULL;
}

void SingleLinkedList::insertInMid(int num, int index){
    temp=new Node();
    temp->data = num;
    temp->next = NULL;
    ptr=head;
    int count=1;
    while(count!=index-1){
        ptr=ptr->next;
        count++;
    }
    temp->next=ptr->next;
    ptr->next=temp;
    temp=ptr=NULL;
}

void SingleLinkedList::deleteFromEnd(){
    temp=head;
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    delete(temp->next);
    temp->next=NULL;

}

void SingleLinkedList::deleteFromStart(){
    temp=head;
    head=temp->next;
    delete(temp);
}

void SingleLinkedList::deleteFromMid(int num){
    temp=head;
    while(temp->next->data!=num){
        temp=temp->next;
    }
    ptr=temp->next;
    temp->next=ptr->next;
    delete(ptr);
}

void SingleLinkedList::searchNumber(int num){
    temp=head;
    int ctr=0,count=1;
    while(temp!=NULL){
        if(temp->data==num){
            ctr=1;
            break;
        }
        temp=temp->next;
        count++;
    }
    if(ctr==0){
        cout<<"Number not found!!!"<<endl;
    }
    else
        cout<<"Number found at position: "<<count<<endl;
}

void SingleLinkedList::reverseLinkedList(){
    current=head;
    temp=ptr=NULL;
    while(current != NULL){
        ptr=current->next;
        current->next = temp;
        temp=current;
        current=ptr;
    }
    head=temp;
}

SingleLinkedList SingleLinkedList::operator+(SingleLinkedList &ob){
    SingleLinkedList ob1=*this;
    temp=ob1.head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=ob.head;
    return ob1;
}

void SingleLinkedList::display(){
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
    SingleLinkedList ob,ob1,ob2,ob3;char ch;
    do{
        cout<<"Enter 1 to display the Single Linked List."<<endl;
        cout<<"Enter 2 to insert element at start."<<endl;
        cout<<"Enter 3 to insert element in the end."<<endl;
        cout<<"Enter 4 to insert element in the middle."<<endl;
        cout<<"Enter 5 to delete element at start."<<endl;
        cout<<"Enter 6 to delete element in the end."<<endl;
        cout<<"Enter 7 to delete element in the middle."<<endl;
        cout<<"Enter 8 to search element in the Linked List."<<endl;
        cout<<"Enter 9 to reverse the Single Linked List."<<endl;
        cout<<"Enter 10 to concatenate two Single Linked List."<<endl;
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
        case 9:
            ob.reverseLinkedList();
            cout<<"Reversed Linked List:"<<endl;
            ob.display();
            break;
        case 10:
            int c;
            cout<<"You have to insert two linked list.Enter 1 to use your previous linked list.";
            cin>>c;
            int n;
            cout<<"Enter number of nodes in Second SLL:";
            cin>>n;
            cout<<"Enter elements:";
            cin>>num;
            ob2.insertAtStart(num);
            for(int i=2;i<=n;i++){
                cin>>num;
                ob2.insertAtEnd(num);
            }
            if(c!=1){
                cout<<"Enter number of nodes in SLL:";
                cin>>n;
                cout<<"Enter elements:";
                cin>>num;
                ob1.insertAtStart(num);
                for(int i=2;i<=n;i++){
                    cin>>num;
                    ob1.insertAtEnd(num);
                }
                ob3=ob1+ob2;
            }
            else{
                ob3=ob+ob2;
            }
            cout<<"Concatenated Linked list:";
            ob3.display();
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
