class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> output;
        int max = 0;
        
        for(int i=0; i<candies.size(); i++)
        {
            if(max < candies[i])
            {
                max = candies[i];
            }
        }

        for(int i=0; i<candies.size(); i++)
        {
            if(candies[i]+extraCandies >= max){
                output.push_back(true);
            }
            else{
                output.push_back(false);
            }
        }
        return output;
    }
};
