class Solution {  // 0419 11:48~12:00
public:
    vector<string> fizzBuzz(int n) {
        vector<string> result;
        
        for(int i=1;i<n+1;i++){
            string nowTurn = "";
            if(i%3 == 0)
                nowTurn += "Fizz";
            if(i%5 == 0)
                nowTurn += "Buzz";
            if(nowTurn =="")
                nowTurn = to_string(i);
            
            result.push_back(nowTurn);
        }
        return result;
    }
};

// 2차원 벡터 관련
