#include <iostream>
using namespace std;

void printArray(int arr[], int n){
     for(int i=0; i< n; i++){
        cout<< arr[i]<<" ";
    }
    cout<<endl;
}

void insertionSort(int arr[], int n){
   for(int i = 1; i < n; i++){
        int curr = arr[i];
        int pre = i - 1;
        while(pre >= 0 && arr[pre] > curr){
            arr[pre + 1] = arr[pre];
            pre --;
        }
        arr[pre + 1] = curr;
   }

}
int main(){
    int n = 5;
    int arr[] ={4, 1, 5, 2, 3};
    insertionSort(arr,n);
    printArray(arr, n);

    return 0;
}