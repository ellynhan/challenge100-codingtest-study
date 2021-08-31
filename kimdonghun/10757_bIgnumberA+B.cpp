#include <iostream>
#include <algorithm>

using namespace std;

string A;
string B;

char C[10000];

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);


	// ******* INPUT *******
	cin >> A;
	cin >> B;

	int carry = 0;
	int digitSum = 0;

	int bigSize = max(A.size(), B.size());
	reverse(A.begin(), A.end());
	reverse(B.begin(), B.end());


	int totSize = 0;

    // ******* PROCESS *******
    for(int i = 0; i < bigSize; i++) {
        if(i > B.size() - 1) {
            digitSum = (A[i] - '0');
        }
        else if(i > A.size() - 1) {
            digitSum = (B[i] - '0');
        }
        else {
            digitSum = (A[i] - '0') + (B[i] - '0');
        }


        digitSum += carry;

        if(digitSum >= 10) {
            carry = 1;
            digitSum -= 10;
        }
        else {
            carry = 0;
        }

        //cout << digitSum;
        C[i] = digitSum + '0';

        if(i == bigSize - 1 && carry) {
            C[++i] = '1';
            totSize++;
        }

        digitSum = 0;
        totSize++;
    }



    // ******* OUTPUT *******
    for(int i = totSize-1 ; i >= 0; i--) {
        cout << C[i];
    }

	return 0;
}
