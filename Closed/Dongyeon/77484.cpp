#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    int zero_count=0, count=0;
    for (int i=0 ; i < lottos.size() ; i++){
    	if(lottos[i] ==0 ){
    		zero_count ++;
		}
		else{
			for (int j=0 ; j< win_nums.size() ; j ++){
				if (lottos[i] == win_nums[j]) {
					count ++;
					win_nums.erase(win_nums.begin() + j);
				}
			}
		}
	}
    cout << "zerocount : " << zero_count << " count : " << count << endl;
	int minn, maxn;
	
	if (count < 2){
		minn = 6;
	}
	else{
		minn = 7-count ;
	}
	if (count + zero_count < 2){
		maxn = 6;
	}
	else{
		maxn = 7 - (count + zero_count);
	}
	answer.push_back(maxn);
	answer.push_back(minn);
	
	
    return answer;
}
