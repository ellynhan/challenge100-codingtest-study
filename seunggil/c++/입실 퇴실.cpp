#include <string>
#include <vector>
#include <map>
#include <queue>
#include <set>

using namespace std;

vector<int> solution(vector<int> enter, vector<int> leave) {
    map<int,int> result;
    set<int> in;
    queue<int> out(deque<int>(leave.begin(), leave.end()));

    set<int>::iterator iter;
    for(int i : enter){
        for(int people : in)
                result[people]++;

        result[i] = in.size();
        if(i == out.front()){
            out.pop();
            iter = in.find(out.front());
            while(iter != in.end()){
                in.erase(iter);
                out.pop();
                iter = in.find(out.front());
            }
        }else
            in.insert(i);
    }

    vector<int> answer;
    for(const pair<const int, int>& iter : result)
        answer.push_back(iter.second);

    return answer;
}
