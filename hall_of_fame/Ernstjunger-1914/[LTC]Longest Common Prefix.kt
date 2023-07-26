class Solution {
    fun longestCommonPrefix(strs: Array<String>): String {
        when(strs.size) {
            0 -> return ""
            1 -> return strs[0]
        }
        
        var lcp = strs[0]
        
        for(i in 1 .. strs.size - 1) {
            println(lcp)
            
            var len1 = lcp.length
            var len2 = strs[i].length
            var minlen = Math.min(len1, len2)
            
            lcp = lcp.slice(IntRange(0, minlen - 1))
            
            for(j in 0 .. minlen - 1) {
                if(lcp[j] != strs[i][j]) {
                    lcp = lcp.slice(IntRange(0, j - 1))
                    
                    break
                }
            }
        }
        return lcp
    }
}