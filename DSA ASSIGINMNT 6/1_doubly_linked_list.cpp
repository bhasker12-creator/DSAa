#include <iostream>
using namespace std;
struct Node{int data;Node*prev;Node*next;};
Node*head=nullptr;
void insertBeginning(int val){
Node*n=new Node{val,nullptr,head};
if(head!=nullptr)head->prev=n;
head=n;
}
void insertEnd(int val){
Node*n=new Node{val,nullptr,nullptr};
if(head==nullptr){head=n;return;}
Node*temp=head;
while(temp->next!=nullptr)temp=temp->next;
temp->next=n;
n->prev=temp;
}
void insertAfter(int refVal,int val){
Node*temp=head;
while(temp!=nullptr&&temp->data!=refVal)temp=temp->next;
if(temp==nullptr){cout<<"Node not found\n";return;}
Node*n=new Node{val,temp,temp->next};
if(temp->next!=nullptr)temp->next->prev=n;
temp->next=n;
}
void insertBefore(int refVal,int val){
Node*temp=head;
while(temp!=nullptr&&temp->data!=refVal)temp=temp->next;
if(temp==nullptr){cout<<"Node not found\n";return;}
if(temp==head){insertBeginning(val);return;}
Node*n=new Node{val,temp->prev,temp};
temp->prev->next=n;
temp->prev=n;
}
void deleteNode(int val){
Node*temp=head;
while(temp!=nullptr&&temp->data!=val)temp=temp->next;
if(temp==nullptr){cout<<"Node not found\n";return;}
if(temp->prev!=nullptr)temp->prev->next=temp->next;
else head=temp->next;
if(temp->next!=nullptr)temp->next->prev=temp->prev;
delete temp;
}
void search(int val){
Node*temp=head;
int pos=1;
while(temp!=nullptr){
if(temp->data==val){cout<<"Found at position "<<pos<<"\n";return;}
temp=temp->next;
pos++;
}
cout<<"Not found\n";
}
void display(){
Node*temp=head;
if(temp==nullptr){cout<<"List is empty\n";return;}
while(temp!=nullptr){
cout<<temp->data<<" ";
temp=temp->next;
}
cout<<"\n";
}
int size(){
int count=0;
Node*temp=head;
while(temp!=nullptr){count++;temp=temp->next;}
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
