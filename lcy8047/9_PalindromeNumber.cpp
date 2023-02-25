class Solution {
public:
    bool isPalindrome(int x) {
        std::string target_num = std::to_string( x );
        int left = 0;
        int right = target_num.size() - 1;
        while ( left < right )
        {
            if ( target_num[left] != target_num[right] )
            {
                return false;
            }
            left ++;
            right --;
        }
        return true;
    }
};