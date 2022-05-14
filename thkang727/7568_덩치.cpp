#include <iostream>

using namespace std;

int main()
{
    int n;

    cin >> n;
    int arr[n][3]={ };
    for(int i=0;i<n;i++){
        cin >> arr[i][0] >> arr[i][1];
        arr[i][2] = 1;
        if (i==0){arr[i][3] = 1;}
        else {
            for(int j=0;j<i;j++){
                if(arr[i][0] > arr[j][0] && arr[i][1] > arr[j][1] ){
                    arr[j][2]++;
                }
                else if(arr[i][0] < arr[j][0] && arr[i][1] < arr[j][1]){
                    arr[i][2]++;
                }
                else{

                }
            }
        }

    }
    for(int i=0;i<n;i++){
        cout << arr[i][2] << " ";
    }
    return 0;
}
