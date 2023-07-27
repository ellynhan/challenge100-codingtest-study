class Solution {
    fun isPalindrome(x: Int): Boolean {
        var Xstr = x.toString()
        
        while(Xstr.length > 1) {
            if(Xstr[0] != Xstr[Xstr.length - 1]) {
                return false
            } else {
                Xstr = Xstr.slice(IntRange(1, Xstr.length - 2))
            }
        }
        return true
    }
}