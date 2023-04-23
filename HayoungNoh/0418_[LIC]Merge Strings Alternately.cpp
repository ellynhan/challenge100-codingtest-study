class Solution {  // 04.19 12:14~12:35
public:
    string mergeAlternately(string word1, string word2) {
        string result = "";
        int len1 = word1.size();
        int len2 = word2.size();
        int n1=0, n2=0;
        for(int i=0; i<len1+len2; i++){
            if((len1>n1 && i%2==0) || len2<=n2)
            {   
                result += word1[n1];
                n1++;
            }else if((len2>n2 && i%2 ==1) || len1<=n1){
                result += word2[n2];
                n2++;
            }
            
            
        }
        return result;
    }
};

//string 관련 활용
