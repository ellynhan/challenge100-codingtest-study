#include <iostream>
using namespace std;

int arr[1001]={0, 1, 3 };

int main(){
	int N; cin >> N;
    
    for(int i=3; i<=N; i++){
        arr[i] = (arr[i-1] + arr[i-2] * 2) % 10007;
    }

    cout << arr[N];

	return 0;
}
