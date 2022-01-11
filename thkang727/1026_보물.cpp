/*
    boj 1026 보물
*/


#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int sum=0,n;
    cin >> n;
    if (n>0 && n<=50){
        int arr[n], arr_b[n];
        for(int k =0; k<n;k++){
            cin>> arr[k];
            if(arr[k]>=100 && arr[k]<0) return 0;
        }
        sort(arr, arr+n);
        for(int k =0; k<n;k++){
            cin>> arr_b[k];
            if(arr_b[k]>=100 && arr_b[k]<0) return 0;
        }
        sort(arr_b,arr_b+n, greater<int>());

        for(int i=0;i<n;i++){
            sum += arr[i]*arr_b[i];
        }
        cout << sum;
    }
    return 0;
}
