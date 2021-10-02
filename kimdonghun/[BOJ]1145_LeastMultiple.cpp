#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int N;
int arr[5];


int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);


	for(int i = 0; i < 5; i++) {
        cin >> arr[i];
	}

	int dividePossibleCnt = 0;
	int leastMultiple = 0;

	for(int i = 1; i < 10000000000; i++ ){
        for(int j = 0; j < 5; j++) {
            if(i % arr[j] == 0) {
                dividePossibleCnt++;
            }
        }

        if(dividePossibleCnt >= 3) {
            leastMultiple = i;
            break;
        }

        dividePossibleCnt = 0;
	}

	cout << leastMultiple;



	return 0;
}
