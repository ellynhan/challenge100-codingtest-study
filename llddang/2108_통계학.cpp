#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(){
	int N; cin >> N;

	vector<int> vec(N);
	int i=0, sum = 0;
	for(; i<N; i++){
        cin >> vec[i];
        sum += vec[i];
	}
    stable_sort(vec.begin(), vec.end());
    
    // 산술 평균
    int mean = round((float)sum / N);
    cout << mean << "\n";
    
    // 중앙값
    cout << vec[N/2] << "\n";
    
    // 최빈값
    vector<int> maxFreq;
    int cnt=1, prev=4001, freq=0;
    for(i=0; i<N; i++){
        while(prev == vec[i]){
            cnt++;
            i++;
        }
        if(cnt != 1) i--;
        if(cnt > freq){
            maxFreq.clear();
            maxFreq.push_back(vec[i]);
            freq = cnt;
        } else if (cnt == freq){
            maxFreq.push_back(vec[i]);
        }
        cnt = 1;
        prev = vec[i];
	}
    cout << ((maxFreq.size() > 1) ? maxFreq[1] : maxFreq[0]) << "\n";
    
    // 범위
    if(N == 1) cout << "0";
    else cout << vec[N-1] - vec[0];
}
