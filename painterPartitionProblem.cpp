#include <iostream>
#include <vector>
using namespace std;

bool isPossible(vector<int> &arr, int n, int m, int maxTimeToPaint){
    int painters = 1, time =0;
    for(int i = 0; i < n; i++){
        if (time + arr[i] <= maxTimeToPaint){
            time+= arr[i];

        }
        else{
            painters ++;
            time = arr[i];
        }
    }
    return painters <= m ? true : false ;
}

int mainTimeToPaint(vector<int> &arr, int n, int m){
    int sum = 0, maxVal = INT32_MIN;
    for(int i = 0; i < n; i++){
        sum+= arr[i];
        maxVal = max(maxVal, arr[i]);

    }

    int st= maxVal, end = sum;
    while(st <= end){
        int mid = st + (end - st) / 2;
        
        if (isPossible(arr,n,m,mid)) // left search
        {
            end = mid - 1;
        }
        else // right search
        {
            st = mid + 1;
        }
    }

}
int main (){

    vector <int> arr= {40, 30, 10, 20};
    int n = 4, m = 2;
    cout<< mainTimeToPaint(arr, n, m) << endl;
    return 0;
}
