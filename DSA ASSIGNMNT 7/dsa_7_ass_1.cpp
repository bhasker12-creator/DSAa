#include <iostream>
using namespace std;
int main() {
    int arr[10]={5,2,4,1,3,6,3,8,10,9};

        
        for(int i=0;i<10-1;i++){
            int min=i;
            for(int j=i+1;j<10-1;j++){
                if(arr[min]>arr[j]){
                          min=j;
                    
                }
            
            }
             swap(arr[min],arr[i]);
        }
    
    for(int i=0;i<10;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}