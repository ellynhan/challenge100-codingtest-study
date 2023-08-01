#include <iostream>
#include <cmath>
using namespace std;

int secondLow(int a, int b, int c, int d){
    int min1 = min(a, b);
    int min2 = min(c, d);
    int max1 = max(a, b);
    int max2 = max(c, d);
    if(min1 < min2)
        return min(min2, max1);
    else
        return min(min1, max2);
}

int main()
{
    int arr[1025][1025];
    int N; cin >> N;
    int i, j;
    for(i=0; i<N; i++){
        for(j=0; j<N; j++){
            cin >> arr[i][j];
        }
    }
    
    while(N != 0){
        for(i=0; i<N/2; i++){
            for(j=0; j<N/2; j++){
                arr[i][j] = secondLow(arr[2*i][2*j],arr[2*i+1][2*j], arr[2*i+1][2*j+1], arr[2*i][2*j+1]);
            }
        }
        N/=2;
    }
    
    cout << arr[0][0];
}
