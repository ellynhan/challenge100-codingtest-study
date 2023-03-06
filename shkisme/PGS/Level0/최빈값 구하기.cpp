#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<int> array) {
    int answer = 0;
    map<int, int> myMap;

    for (int a : array){
				myMap[a]++;
    }

    int max = -1;

    for (auto m : myMap){
        if (m.second > max){
            max = m.second;
            answer = m.first;
        }
				else if (m.second == max){
						return -1;
				}
    }

    return answer;
}
