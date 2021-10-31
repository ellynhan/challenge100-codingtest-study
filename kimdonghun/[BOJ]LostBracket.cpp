#include <iostream>
#include <string>

using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    string seqOp;


	// ******* INPUT *******
	cin >> seqOp;

    int curIndex = 0;
    string tmpStr = "";

    int numArr[50];
    char opArr[50];
    int numIndex = 0;
    int opIndex = 0;

    // ******* PROCESS *******
    for(int i = 0; i < seqOp.size(); i++) {
        //cout << seqOp[i] << "\n";

        if(i == seqOp.size() - 1) {
            //cout << "!\n";
            tmpStr += seqOp[i];
            numArr[numIndex++] = stoi(tmpStr);

            break;
        }

        if(seqOp[i] != '+' && seqOp[i] != '-') {
            //cout << "?\n";
            tmpStr += seqOp[i];
        }
        else {
            numArr[numIndex++] = stoi(tmpStr);
            opArr[opIndex++] = seqOp[i];
            tmpStr = "";
        }


    }


    /*
    for(int i = 0; i < numIndex; i++) {
        cout << numArr[i] << "\n";
    }

    for(int i = 0; i < opIndex; i++) {
        cout << opArr[i] << "\n";
    }
    */


    int sumRes = 0;

    //cout << numIndex << " " << opIndex << "\n";

    int res = numArr[0];
    for(int i = 0; i < opIndex; i++) {
        if(opArr[i] == '+') {
            res += numArr[i+1];
        }
        else {
            //cout << numArr[i+1] << "---\n";
            int j;
            int sumSum = 0;
            sumRes = numArr[i+1];

            for(j = i+1; j < opIndex; j++) {
                if(opArr[j] == '+') {
                    sumSum++;
                    sumRes += numArr[j+1];
                }
                else
                    break;
            }

            //cout << sumRes << "===\n";
            res -= sumRes;
            sumRes = 0;

            i += (sumSum);
        }

        //cout << res << "\n";
    }


    // ******* OUTPUT *******
    cout << res;

	return 0;
}
