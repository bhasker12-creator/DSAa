#include <iostream>
using namespace std;
struct Node{int data;Node*next;};
bool isCircular(Node*head){
if(head==nullptr)return false;
Node*slow=head;
Node*fast=head;
while(fast!=nullptr&&fast->next!=nullptr){
slow=slow->next;
fast=fast->next->next;
if(slow==fast)return true;
}
return false;
}
int main(){
int n;
cout<<"Enter number of nodes: ";
cin>>n;
Node*head=nullptr;
Node*tail=nullptr;
for(int i=0;i<n;i++){
int val;
cout<<"Enter value "<<i+1<<": ";
cin>>val;
Node*n1=new Node{val,nullptr};
if(head==nullptr)head=tail=n1;
else{tail->next=n1;tail=n1;}
}
int makeCircular;
cout<<"Make it circular? (1=Yes 0=No): ";
cin>>makeCircular;
if(makeCircular){
int pos;
cout<<"Connect last node to which position (1 to "<<n<<"): ";
cin>>pos;
Node*temp=head;
for(int i=1;i<pos;i++)temp=temp->next;
tail->next=temp;
}
if(isCircular(head))cout<<"Circular Linked List\n";
else cout<<"Not a Circular Linked List\n";
return 0;
}
