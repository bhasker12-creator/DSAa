#include <iostream>
using namespace std;
int main(){
    int arr[10]={5,2,4,1,3,6,3,8,10,9};
    int n=10;
      for(int i=n-1;i>0;i--){
        for(int j=0;j<i;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }

      }
    for(int i=0;i<10;i++){
        cout<<arr[i]<<" ";
    }    
        
}