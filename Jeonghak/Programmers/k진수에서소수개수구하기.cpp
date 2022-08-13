#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;
	
bool isPrime(long n) {
    if(n==1) return false;
	for (int i = 2; i <= sqrt(n); i++) {
		if (n%i == 0) {
			return false;
		}
	}
	return true;
}

int solution(int n, int k) {
    int answer = 0;
    vector<long> converted;
    string temp = "";

    while(n>0){
        converted.push_back(n%k);
        n/=k;
    }
    
    for(int i=converted.size() - 1; i>=0; i--){
        if(converted[i] != 0){
            temp += converted[i] + '0';
        }
        if(converted[i] == 0 || i == 0){
            if(temp != "" && isPrime(stol(temp))){
                answer++;
            }
            temp = "";
        }
    }
    return answer;
}