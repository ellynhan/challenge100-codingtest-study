#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

#define FOR(i, j) for(int i = 0; i < j; i++)

using namespace std;

map<char, int> characters;
int arr[8] = {0, 1, 2, 3, 4, 5, 6, 7};

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int N, vector<string> data) {
    int answer = 0;
    characters.insert({'A', 0});
    characters.insert({'C', 1});
    characters.insert({'F', 2});
    characters.insert({'J', 3});
    characters.insert({'M', 4});
    characters.insert({'N', 5});
    characters.insert({'R', 6});
    characters.insert({'T', 7});
    do {
        bool flag = true;
        FOR(n, N) {
            char a  = data[n][0];
            char b  = data[n][2];
            char op = data[n][3];
            int num = data[n][4] - '0';
            // cout << num << '\n';
            if (op == '=') {
                if (abs(arr[characters[a]] - arr[characters[b]]) != num + 1) {
                    flag = false;
                    break;
                }
            } else if (op == '>') {
                if (abs(arr[characters[a]] - arr[characters[b]]) <= num + 1) {
                    flag = false;
                    break;
                }
            } else if (op == '<') {
                if (abs(arr[characters[a]] - arr[characters[b]]) >= num + 1) {
                    flag = false;
                    break;
                }
            }
        }
        if (flag) answer++;
	} while (next_permutation(&arr[0], &arr[8]));
    return answer;
}