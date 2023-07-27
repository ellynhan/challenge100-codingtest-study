#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int N;


int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);


    char curSlot;
    int totPiece = 0;
    int curNum = 0;

	// ******* INPUT *******
	for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            cin >> curSlot;


            if(curSlot == 'F' && curNum % 2 == 0 && i % 2 == 0) {
                totPiece++;
            }
            else if(curSlot == 'F' && curNum % 2 == 1 && i % 2 == 1) {
                totPiece++;
            }

            curNum++;

        }
        curNum = 0;
	}

	cout << totPiece;


	return 0;
}
