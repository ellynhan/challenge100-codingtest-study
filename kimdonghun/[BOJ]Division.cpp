#include <iostream>
#include <string>

using namespace std;


int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	string N;
    int F;


	// ******* INPUT *******
	cin >> N;
	cin >> F;

	int sizeStr = N.size();
	int curNum = 0;

	bool stopFlag = false;

	//cout << sizeStr << "\n";

	// ******* PROCESS *******
	for(int i = 0; i <= 9; i++) {
        if(stopFlag) {
            break;
        }

        for(int j = 0; j <=  9; j++) {
            N[sizeStr-1] = '0' + j;
            N[sizeStr-2] = '0' + i;

            curNum = stoi(N);
            //cout << curNum <<"\n";

            if(curNum % F == 0) {
                stopFlag = true;
                break;
            }
        }

	}

	cout << N[sizeStr-2] << N[sizeStr-1];

	return 0;
}
