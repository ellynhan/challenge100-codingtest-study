//0301
#include <string>
#include <vector>

using namespace std;

string solution(vector<vector<int>> scores) {
    string answer = "";
    for(int i=0; i<scores.size(); i++){
        int isMaxSelf = 1;
        int isMinSelf = 1;
        int sum = 0;
        int selfScore = scores[i][i];
        int num = scores.size();
        
        for(int j=0; j<scores.size(); j++){
            if(j==i)continue;
            if(selfScore >= scores[j][i]){
                isMinSelf = 0;
            }
            if(selfScore <= scores[j][i]){
                isMaxSelf = 0;
            }
            sum += scores[j][i];
        }
        
        if(isMinSelf == 1 || isMaxSelf ==1){
            num -= 1;
        }else{
            sum += selfScore;
        }
        
        double avg = sum/num;
        
        if(avg >= 90){
            answer += "A";
        }else if(avg >=80){
            answer += "B";            
        }else if(avg >=70){
            answer += "C";
        }else if(avg >=50){
            answer += "D";
        }else{
            answer += "F";
        }
    }
    return answer;
}
