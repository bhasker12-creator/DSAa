#include <iostream>
using namespace std;
struct Node{int data;Node*next;};
Node*head=nullptr;
void insertBeginning(int val){
Node*n=new Node{val,nullptr};
if(head==nullptr){n->next=n;head=n;return;}
Node*temp=head;
while(temp->next!=head)temp=temp->next;
n->next=head;
temp->next=n;
head=n;
}
void insertEnd(int val){
Node*n=new Node{val,nullptr};
if(head==nullptr){n->next=n;head=n;return;}
Node*temp=head;
while(temp->next!=head)temp=temp->next;
temp->next=n;
n->next=head;
}
void insertAfter(int refVal,int val){
if(head==nullptr){cout<<"List is empty\n";return;}
Node*temp=head;
do{
if(temp->data==refVal){
Node*n=new Node{val,temp->next};
temp->next=n;
return;
}
temp=temp->next;
}while(temp!=head);
cout<<"Node not found\n";
}
void insertBefore(int refVal,int val){
if(head==nullptr){cout<<"List is empty\n";return;}
if(head->data==refVal){insertBeginning(val);return;}
Node*temp=head;
do{
if(temp->next->data==refVal){
Node*n=new Node{val,temp->next};
temp->next=n;
return;
}
temp=temp->next;
}while(temp!=head);
cout<<"Node not found\n";
}
void deleteNode(int val){
if(head==nullptr){cout<<"List is empty\n";return;}
if(head->next==head){
if(head->data==val){delete head;head=nullptr;}
else cout<<"Node not found\n";
return;
}
if(head->data==val){
Node*temp=head;
while(temp->next!=head)temp=temp->next;
Node*oldHead=head;
head=head->next;
temp->next=head;
delete oldHead;
return;
}
Node*curr=head->next,*prev=head;
while(curr!=head){
if(curr->data==val){
prev->next=curr->next;
delete curr;
return;
}
prev=curr;curr=curr->next;
}
cout<<"Node not found\n";
}
void search(int val){
if(head==nullptr){cout<<"List is empty\n";return;}
Node*temp=head;
int pos=1;
do{
if(temp->data==val){cout<<"Found at position "<<pos<<"\n";return;}
temp=temp->next;pos++;
}while(temp!=head);
cout<<"Not found\n";
}
void display(){
if(head==nullptr){cout<<"List is empty\n";return;}
Node*temp=head;
do{
cout<<temp->data<<" ";
temp=temp->next;
}while(temp!=head);
cout<<head->data<<"\n";
}
int size(){
if(head==nullptr)return 0;
int count=0;
Node*temp=head;
do{count++;temp=temp->next;}while(temp!=head);
return count;
}
int main(){
int choice,val,refVal;
while(true){
cout<<"\n1.Insert Beginning\n2.Insert End\n3.Insert After\n4.Insert Before\n5.Delete\n6.Search\n7.Display\n8.Size\n9.Exit\nEnter choice: ";
cin>>choice;
if(choice==1){cout<<"Enter value: ";cin>>val;insertBeginning(val);}
else if(choice==2){cout<<"Enter value: ";cin>>val;insertEnd(val);}
else if(choice==3){cout<<"Enter reference value: ";cin>>refVal;cout<<"Enter value: ";cin>>val;insertAfter(refVal,val);}
else if(choice==4){cout<<"Enter reference value: ";cin>>refVal;cout<<"Enter value: ";cin>>val;insertBefore(refVal,val);}
else if(choice==5){cout<<"Enter value to delete: ";cin>>val;deleteNode(val);}
else if(choice==6){cout<<"Enter value to search: ";cin>>val;search(val);}
else if(choice==7)display();
else if(choice==8)cout<<"Size: "<<size()<<"\n";
else if(choice==9)break;
else cout<<"Invalid choice\n";
}
return 0;
}
