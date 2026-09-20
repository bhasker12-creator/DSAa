#include <iostream>
using namespace std;
int main(){
     int arr[10]={5,2,4,1,3,6,3,8,10,9};
      for(int i=0;i<10-1;i++){
        int j=i;
        while(j>0 && arr[j-1]>arr[j]){
            if(arr[j-1]>arr[j]){
                swap(arr[j],arr[j-1]);
            }
            j--;
        }
      }
      for(int i=0;i<10;i++){
        cout<<arr[i]<<" ";}
        
        
}