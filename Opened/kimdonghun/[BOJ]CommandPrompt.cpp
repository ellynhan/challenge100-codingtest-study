#include <iostream>
#include <string>

using namespace std;


int N;
string myStr[51];

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);


	// ******* INPUT *******
	cin >> N;

	for(int i = 0; i <N; i++) {
        cin >> myStr[i];
	}

	bool difchar = false;
	string answerStr = myStr[0];
	int strSize = myStr[0].size();

	for(int i = 0; i < strSize; i++) {
        for(int j = 0; j< N; j++) {
            answerStr[i] = myStr[j][i];

            //cout << myStr[j][i] << "\n";

            if( j > 0 && myStr[j][i] != myStr[j-1][i]) {
                difchar = true;
            }

        }

        if(difchar) {
            answerStr[i] = '?';
            difchar = false;
        }


	}

	cout << answerStr;

	return 0;
}
