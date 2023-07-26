#include <iostream>

#define MAX 1500000000

using namespace std;

long long N;
long long cityGasArr[100001];
long long dstArr[100001];

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);


	// ******* INPUT *******
	cin >> N;

	long long minGas = 0;
	long long cityGasCost;
	long long cityDst;


    for(int i = 0; i < N-1; i++) {
        cin >> dstArr[i];
	}


	for(int i = 0; i < N-1; i++) {
        cin >> cityGasArr[i];
	}


    // ******* PROCESS *******
    long long curMax = MAX;


    // refill gas by minimum price
    for(int i = 0; i < N-1; i++) {
        if(curMax > cityGasArr[i]) {
            curMax = cityGasArr[i]; // find cheaper gas (change max)
        }

        minGas += (long long) curMax * dstArr[i];
    }


    // ******* OUTPUT *******
    cout << minGas;

	return 0;
}
