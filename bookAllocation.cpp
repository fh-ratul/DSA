#include <iostream> 
#include <vector> 
using namespace std; 

bool isValid(vector<int> &arr, int n, int m, int mid ){
    int stu = 1, pages = 0;
    for(int i=0; i< n; i++){
        if (arr[i] > mid){
            return false;
        }
        if(pages + arr[i] <= mid){
            pages+= arr[i];
        }
        else
        {
            stu ++;
            pages = arr[i];
        }
    }

    return stu > m ? false : true;
}

int allocateBooks(vector<int> &arr, int n, int m) {
    if (m > n){
        return -1;
    }
  int sum = 0;
  for(int i =0; i<n; i++){
    sum+= arr[i];
  }
  
  int st = 0, end = sum, ans = -1;
  while(st <= end){
    
    int mid = st + (end - st) / 2;
    if (isValid(arr, n, m, mid)) // Valid_left search
    {   
        ans = mid;
        end = mid - 1;
    }
    else // invalid_Right search
    {
        st = mid + 1;
    }
  }
}

int main() {
    vector<int> arr = {2, 1, 3, 4};
    int n = 4, m = 2; 
    cout << allocateBooks(arr, n, m) << endl;
    return 0;
}
