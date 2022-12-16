class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        std::string common_prefix = strs[0];
        for ( auto s : strs )
        {
            for ( size_t i = 0; i < common_prefix.size(); ++ i )
            {
                if ( s[i] != common_prefix[i] )
                {
                    size_t common_prefix_size = common_prefix.size();
                    for ( size_t k = 0; k < common_prefix_size - i; ++ k )
                    {
                        common_prefix.pop_back();
                    }
                    break;
                }
            }
            if ( common_prefix.size() == 0 )
            {
                return "";
            }
        }
        return common_prefix;
    }
};