#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    sort(nums.begin(), nums.end());
    
    int type = nums[0];
    int cnt = 1;
    for(int i = 1; i < nums.size(); i++){
        if(type != nums[i]){
            cnt++;
            type = nums[i];
        }
    }
    if(nums.size() / 2 >= cnt) answer = cnt;
    else answer = nums.size() / 2;

    return answer;
}
