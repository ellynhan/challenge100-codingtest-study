#include <iostream>
#include <stack>

using namespace std;

int N;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	stack<int> s;

	// ******* INPUT *******
	cin >> N;
	string answer = "";

	int preNum = 0;
	int curNum = 0;
	int curStackNum = 0;

	bool isPossible = true;

	for(int i = 0; i < N; i++) {
        cin >> curNum;

        while(curStackNum < curNum) {
            s.push(curStackNum);
            curStackNum++;
            answer+= "+";
            //cout << "+\n";
        }

        if(curStackNum >= curNum) {
            if( (s.top() + 1) != curNum) {
                isPossible = false;
                //break;
            }

            //cout << s.top() + 1<<"\n";
            s.pop();
            answer+= "-";

            //cout << "-\n";
        }

        preNum = curNum;
	}

    // ******* PROCESS *******


    // ******* OUTPUT *******
    if(isPossible) {
        for(int i = 0; i < answer.size() ;i++) {
            cout << answer[i] << "\n";
        }
    }
    else {
        cout << "NO\n";
    }

	return 0;
}
