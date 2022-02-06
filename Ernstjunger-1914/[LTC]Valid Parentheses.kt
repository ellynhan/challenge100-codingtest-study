class Solution {
    fun isValid(s: String): Boolean {
        var paren = 0
        var curly = 0
        var square = 0
        val opens: MutableList<Char> = mutableListOf('a')
        
        for(i in 0 .. s.length - 1) {
            when(s[i]) {
                '(' -> {
                    ++paren
                    opens.add(s[i])
                }
                
                '{' -> {
                    ++curly
                    opens.add(s[i])
                }
                
                '[' -> {
                    ++square
                    opens.add(s[i])
                }
                
                ')' -> {
                    --paren
                    
                    if(opens[opens.size - 1] != '(') {
                        return false
                    }
                    
                    opens.removeAt(opens.size - 1)
                }
                
                '}' -> {
                    --curly
                    
                    if(opens[opens.size - 1] != '{') {
                        return false
                    }
                    
                    opens.removeAt(opens.size - 1)
                }
                
                ']' -> {
                    --square
                    
                    if(opens[opens.size - 1] != '[') {
                        return false
                    }
                    
                    opens.removeAt(opens.size - 1)
                }
            }
            if(paren < 0 || curly < 0 || square < 0) {
                return false
            }
        }
        return (paren == 0 && curly == 0 && square == 0)
    }
}