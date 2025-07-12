#include<iostream>
using namespace std;
//max priority Queue the maximum number will be given higer priority and smaller less
class Node{
    public:
    int data;
    int priority;
    Node* next;
    Node(int data,int priority){
        this->data=data;
        this->priority=priority;
        next=nullptr;
    }

};

class Queue{
    Node *front,* rear;
    public:
    Queue(){
        front=rear=nullptr;
    }
    bool isempty(){
        return front==nullptr;
    }
    void Enqueue(){int value,priority;
        cout<<"Enter the value for the node your want to add "<<endl;
        cin>>value;
        cout<<"Enter the priority of the node"<<endl;
        cin>>priority;
        Node * newnode=new Node(value,priority);
        if(isempty()|| priority>front->priority){
            newnode->next=front;
            front=newnode;
            
        }
        else{
            Node * temp=front;
            while(temp!=nullptr&& temp->next->priority>=priority){
                temp=temp->next;
            }
            newnode->next=temp->next;
            temp->next=newnode;
        }
    }

    void Dequeue(){
        if(isempty()){cout<<"The Queue is Empty can't Dequeue"<<endl;
        return;}

        Node* temp=front;
        if(!front->next){
            front=nullptr;
            delete temp;
        }else{
            front=front->next;
            delete temp; 
        }
    }
    void  display(){
        if(isempty()){
            cout<<"The Queue is empty can't display anything"<<endl;
        return;    }

        Node * temp=front;
        while(temp!=nullptr){
        cout<<"Data :"<<temp->data<<" "<<"priority :"<<temp->priority<<" ";
        cout<<endl;
        temp=temp->next;
    }
    cout<<endl;
    }

};
int main(){
    Queue Q;

    int choice;

   do{
    cout<<"1.To Enqueue"<<endl;
    cout<<"2.To Dequeue"<<endl;
    cout<<"3.To Display the Queue"<<endl;
    
    cin>>choice;
    switch(choice){
        case 1:
       Q.Enqueue();
        break;

         case 2:
       Q.Dequeue();
        break;

         case 3:
         Q .display();
       
     break;
        default:
        cout<<"program exit wrong input"<<endl;
}}while(choice>0&&choice<4);
return 0;
}
