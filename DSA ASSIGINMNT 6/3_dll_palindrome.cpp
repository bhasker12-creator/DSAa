#include <iostream>
using namespace std;
struct Node{char data;Node*prev;Node*next;};
Node*head=nullptr;
Node*tail=nullptr;
void insertEnd(char val){
Node*n=new Node{val,nullptr,nullptr};
if(head==nullptr){head=tail=n;return;}
tail->next=n;
n->prev=tail;
tail=n;
}
bool isPalindrome(){
Node*left=head;
Node*right=tail;
while(left!=right&&right->next!=left){
if(left->data!=right->data)return false;
left=left->next;
right=right->prev;
}
return true;
}
int main(){
string s;
cout<<"Enter characters (no spaces), e.g. LEVEL: ";
cin>>s;
for(char c:s)insertEnd(c);
if(isPalindrome())cout<<"True\n";
else cout<<"False\n";
return 0;
}
