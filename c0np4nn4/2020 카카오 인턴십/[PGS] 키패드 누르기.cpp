#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    
    int LPos = 10; int RPos = 12;     // Left hand, Right hand position
        
    for (int i = 0; i < numbers.size(); i++) {
        if (numbers[i] % 3 == 1) {
            LPos = numbers[i];
            answer += "L";
        }
        if (numbers[i] % 3 == 0 && numbers[i] != 0) {
            RPos = numbers[i];
            answer += "R";
        }
        
        if (numbers[i] % 3 == 2 || numbers[i] == 0) {   // 2, 5, 8, 0
            // nearest thumb will click the button
            
            // Row
            int LRow = (LPos / 3) + 1; // LPos == 1, 4, 7, 2, 5, 8
            
            int RRow = RPos / 3; // RPos == 3, 6, 9
            if (RPos % 3 != 0) { // RPos == 2, 5, 8
                RRow = (RPos / 3) + 1;
            }
            
            if (LPos == 0) LRow = 4;
            if (RPos == 0) RRow = 4;
            
            // Column
            int LCol;
            if (LPos % 3 == 1) LCol = 1;    // 1, 4, 7
            if (LPos % 3 == 2) LCol = 2;    // 2, 5, 8
            if (LPos == 0) LCol = 2;        // 0
            
            int RCol;
            if (RPos % 3 == 0) RCol = 3;    // 1, 4, 7
            if (RPos % 3 == 2) RCol = 2;    // 2, 5, 8
            if (RPos == 0) RCol = 2;        // 0
            
            // num Row, Col
            int numRow = numbers[i] / 3 + 1;
            if (numbers[i] == 0) numRow = 4;
            
            int numCol = 2;
            
            
            int LDistance = abs(LRow - numRow) + abs(LCol - numCol);
            int RDistance = abs(RRow - numRow) + abs(RCol - numCol);
            
//            cout << "\n[+] !!!" << endl;
//            cout << LRow << ", " << LCol << endl;
//            cout << RRow << ", " << RCol << endl;
//            cout << numRow << ", " << numCol << endl;
//            cout << LDistance << ", " << RDistance << endl;
            
            if (LDistance == RDistance) {
                if (!hand.compare("left")) { 
					LPos = numbers[i];
					answer += "L"; 
				}
                else { 
					RPos = numbers[i];
					answer += "R"; 
				}
            }
            else if ( LDistance > RDistance ) {
            	RPos = numbers[i];
                answer += "R";
            }
            else {
            	LPos = numbers[i];
                answer += "L";
            }
        }
    }
    return answer;
}
