#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string number, int k) {
    string answer = "";

    int strSize = number.size() - k;
    int curPos = 0;

    //char maxNum;
    int maxIndex = 0;

    for(int i = 0; i < strSize; i++) {
        char maxNum = number[curPos];
        maxIndex = curPos;

        for(int j = curPos; j <= k + i; j++) {
            if(maxNum < number[j]) {
                maxNum = number[j];
                maxIndex = j;
            }
        }

        //cout << maxNum << "\n";
        curPos = maxIndex + 1;
        answer += maxNum;
    }


    return answer;
}
