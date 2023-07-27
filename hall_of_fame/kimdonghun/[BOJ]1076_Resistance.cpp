#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


int N;


int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

    string curColor;
    string totOhm;
    string curOhm;


	// ******* INPUT *******
	for(int i = 0; i < 3; i++) {
        cin >> curColor;


        if(curColor == "black") {
            curOhm = "0";
        } else if(curColor == "brown") {
            curOhm = "1";
        } else if(curColor == "red") {
            curOhm = "2";
        } else if(curColor == "orange") {
            curOhm = "3";
        } else if(curColor == "yellow") {
            curOhm = "4";
        } else if(curColor == "green") {
            curOhm = "5";
        } else if(curColor == "blue") {
            curOhm = "6";
        } else if(curColor == "violet") {
            curOhm = "7";
        } else if(curColor == "grey") {
            curOhm = "8";
        } else {
            curOhm = "9";
        }

        if(i < 2) {
            totOhm += curOhm;
        }
        else {
            for(int i = 0; i < stoi(curOhm); i++) {
                totOhm += "0";
            }
        }

	}

	cout << stoll(totOhm);


	return 0;
}
