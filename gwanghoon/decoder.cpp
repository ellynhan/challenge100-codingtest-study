/*
공과대학 산업공학과
201627547 정광훈
wjdrhkdgnsdl@puasn.ac.kr
*/

#include <iostream> // 표준 입출력 헤더파일
#include <vector> // STL vector 컨테이너
#include <string> // 문자열 클래스
#include <string.h>
#include <algorithm> // 문자열 iteration을 위한 헤더파일
#include <fstream> // 파일 입출력을 위한 헤더파일
#include <sstream> // 문자열을 16진수로 만들기 위한 헤더파일

using namespace std; // std namespace를 전역에 적용

class Encoder{
public:
    Encoder(string inputVal){  // Encoder 클래스의 생성자
        inputString = inputVal;   // Encoder 클래스가 받을 값을 inputString으로 저장
        bracketNum = numBracket(inputString); // 최초로 받은 input값의 괄호 개수를 저장
    }
    ~Encoder(){}     // Encoder 클래스 소멸자

public:
    string inputString; // 최초로 입력받은 문자열 및 변환된 문자열
    string outputString; // 입력받은 문자열의 decode 결과가 될 문자열
    vector<string> outputVector; // 문자열 곱을 위한 string 벡터
    int bracketNum; // 입력받은 문자열의 괄호 개수
    int numBracket(string checkString); // 괄호의 개수를 계산해주는 함수

    bool isValidBracket(string checkString); // 대괄호가 유효한 문자열인지 판단하는 함수
    bool isValidUnit(string Sunit); // encoded된 값이 유요한 문자열인지 판단하는 함수
    bool isValidHex(string Sunit); // 대괄호를 곱할 값이 16진수인지 판단하는 함수
    int makeHex(string hexNum); // 대괄호를 곱할 값은 16진수에서 10진수 정수형으로 변환시켜주는 함수

    void makeVector(string input); // 입력값을 STL을 이용하여 저장하는 함수
    void makeVectorToString(string input); // STL 값을 parsing하여 다시 문자열로 변환시켜주는 함수
    void makeResult(); // outputString에 결과값을 저장해 주는 함수
};

bool Encoder::isValidBracket(string checkString){ // 문자열의 괄호가 올바른지 판별
    int criterion = 0;                            // 왼쪽 대괄호({)가 나오면 1을 더하고 오른쪽 대괄호(})가 나오면 1을 뺀다.
    for(int i = 0; i < checkString.length(); i++){
        char c = checkString[i];
        if (c == '{') {criterion += 1;}
        if (c == '}') {criterion -= 1;}
        if (criterion < 0) {return false;} // criterion이 음수가 되는 순간 올바르지 못한 괄호가 되므로 invalid input으로 간주
    }
    if (criterion == 0) {
        return true;
    }else {        // criterion이 0 이어야 올바른 입력값
        return false;
    }
};

int Encoder::numBracket(string checkString){
    int result = 0;
    for (int i = 0; i < checkString.length(); i++){
        char c = checkString[i];
        if (c == '{') {result += 1;}
    }
    return result;  // 문자열 내에 괄호의 쌍이 몇 개인지 계산한다.
};

int Encoder::makeHex(string hexString){
    unsigned int result;
    stringstream ss;
    ss << hex << hexString;
    ss >> result;
    return static_cast<int>(result); // sstream을 이용하여 0~f의 값을 0~15로 변환
};

void Encoder::makeVector(string input){
    int leftBracketPos = input.find("{");
    int rightBracketPos;
    int criterion = 0;
    for (int i = leftBracketPos; i < input.length(); i++){
        char c = input[i];
        if (c == '{') {criterion += 1;}
        if (c == '}') {criterion -= 1;}
        if (criterion == 0) {rightBracketPos = i; break;}
    }
    if (leftBracketPos == 0){
        return ;
    }
    outputVector.push_back(input.substr(0, leftBracketPos-1));
    outputVector.push_back(input.substr(leftBracketPos-1, 1));
    outputVector.push_back(input.substr(leftBracketPos+1, rightBracketPos-leftBracketPos-1));
    outputVector.push_back(input.substr(rightBracketPos+1));
};

bool Encoder::isValidUnit(string Sunit){
    string unitString = Sunit;
    string unitStringExeption = "0123456789abcdefghijklmnopqrstuvwxyz.,!?@#$%^&*{}";
    for (int i = 0; i < unitStringExeption.length(); i++){
        char c = unitStringExeption[i];
        unitString.erase(
                         remove(
                                unitString.begin(),
                                unitString.end(),c),
                         unitString.end());
    }
    if (unitString.length() != 0) {return false;}
    return true;
};

bool Encoder::isValidHex(string Sunit){
    string unitString = Sunit;
    string unitStringExeption = "0123456789abcdef";
    for (int i = 0; i < unitStringExeption.length(); i++){
        char c = unitStringExeption[i];
        unitString.erase(
                         remove(
                                unitString.begin(),
                                unitString.end(),c),
                         unitString.end());
    }
    if (unitString.length() != 0) {return false;}
    return true;
};

void Encoder::makeVectorToString(string input){
    outputString = "";
    outputVector.clear();
    if (!isValidBracket(input) | !isValidUnit(input)) { outputString = "ERROR: Invalid input"; return;}
    if (input[0] == '{') {outputString = "ERROR: Invalid input"; return;}
    makeVector(input);
    if (!isValidHex(outputVector[1])) { outputString = "ERROR: Invalid input"; return;}
    outputString += outputVector[0];
    for (int i = 0; i < makeHex(outputVector[1]); i++){
        outputString += outputVector[2];
    }
    outputString += outputVector[3];

};

void Encoder::makeResult(){
    if (!isValidBracket(inputString) | !isValidUnit(inputString)) { outputString = "ERROR: Invalid input"; return; }
    if (bracketNum == 0) { outputString = inputString; return; }

    while (numBracket(inputString) != 0){ // 괄호가 없어질 때 까지 연산을 반복
        makeVectorToString(inputString);
        inputString = outputString;
        if (outputString == "ERROR: Invalid input"){ return ;}
    }
}

int main(int argc, char** argv){
    ifstream readFile;
    string FILE_PATH =  argv[1];
    readFile.open(FILE_PATH + "/encoded.txt");
    ofstream writeFile;
    writeFile.open(FILE_PATH + "/decoded.txt");

    if (readFile.is_open()){
        while (!readFile.eof()){
            string inputString;
            getline(readFile, inputString);
            Encoder result(inputString);
            result.makeResult();
            writeFile << result.outputString << endl;
        }
    }
    readFile.close();
    writeFile.close();
    return 0;
}
