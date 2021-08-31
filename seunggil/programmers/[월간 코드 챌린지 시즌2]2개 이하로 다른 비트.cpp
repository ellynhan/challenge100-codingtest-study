#include <string>
#include <vector>
#include <iostream>
using namespace std;

string intToBinary(long long num, int& count) {
    string result = "";
    while (num != 0) {
        if (num % 2) {
            result = "1" + result;
            count++;
        }
        else {
            result = "0" + result;
        }
        num /= 2;
    }

    return result;
}

long long binaryToint(string s) {
    long long result = 0;
    for (char iter : s) {
        if (iter == '1')
            result++;
        result = result << 1;
    }
    result = result >> 1;
    return result;
}

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    int n; // not use
    for (long long iter : numbers) {
        int count = 0;
        string s = intToBinary(iter ^ (iter + 1), count);
        //cout << "count : " + to_string(count) << endl;
        if (count <= 2) {
            answer.push_back(iter + 1);
        }
        else {
            string s1 = intToBinary(iter, n);
            string s2 = intToBinary(iter + 1, n);
            while (s1.size() != s2.size())
                s1 = "0" + s1;

            int i = s.size() - 1;
            int j = s1.size() - 1;
            while (count > 2) {
                if (s[i] == '1') {
                    s2[j] = s1[j];
                    count--;
                }
                i--;
                j--;
            }
            //cout << s2 << endl;
            answer.push_back(binaryToint(s2));
        }
    }

    return answer;
}