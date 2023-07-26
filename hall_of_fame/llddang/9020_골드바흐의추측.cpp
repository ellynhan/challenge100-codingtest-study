#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<int> Eratos(){
	vector<bool> PrimeArray(5100, true);
    vector<int> prime;

	for (int i=2; i*i < 5100; i++){
		if (PrimeArray[i])
			for (int j = i * i; j < 5100; j += i)
			    PrimeArray[j] = false;
	}
	for (int i=2; i < 5100; i++){
		if (PrimeArray[i])
			prime.push_back(i);
	}
	return prime;
}

int main(){
    vector<int> prime = Eratos();
    int testcase; cin >>testcase;
    while(testcase > 0){
        int num; cin >> num;
        int i=0;
        int goldA, goldB;
        while(prime[i] <= num/2){
            int sub = num - prime[i];
            if(find(prime.begin(), prime.end(), sub) != prime.end()){
                goldA = prime[i];
                goldB = sub;
            }
            i++;
        }
        cout << goldA << " " << goldB << "\n";
        testcase--;
    }
}
