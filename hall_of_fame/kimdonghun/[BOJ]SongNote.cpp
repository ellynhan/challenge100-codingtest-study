#include <iostream>

using namespace std;

int N;
int Q;

int noteArr[100];

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);


	// ******* INPUT *******
	cin >> N;
	cin >> Q;

	int acculmulateNum = 0;
	int curNum = 0;

	for(int i = 0; i < N; i++) {
        cin >> curNum;
        acculmulateNum += curNum;
        noteArr[i] = acculmulateNum;
	}


    // ******* PROCESS *******
    int qNum = 0;
    for(int i = 0; i < Q; i++) {
        cin >> qNum;

        for(int j = 0; j < N; j++) {
            if(noteArr[j] > qNum) {
                cout << j+1 << "\n";
                break;
            }
            else if(noteArr[j] == qNum) {
                cout << j+2 << "\n";
                break;
            }

        }

    }


    // ******* OUTPUT *******


	return 0;
}
