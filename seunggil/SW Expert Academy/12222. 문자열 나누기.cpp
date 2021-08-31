#include <iostream>
#include <string>
#include <list>

using namespace std;

int main(int argc, char** argv)
{
    string inputData;
    cin >> inputData;
    int inputDataSize = inputData.length();

    string pre;
    pre += inputData[0];
    inputData = inputData.substr(1);
    string now;
    int answer = 1;
    
    for (int i = 1; i < inputDataSize; i++) {
        now = inputData[0];
        inputData = inputData.substr(1);
        while (pre == now || now == inputData) {
            i++;
            now += inputData[0];
            inputData = inputData.substr(1);
        }
        pre = now;
        answer++;
    }

    return 0;
}