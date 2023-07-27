class Solution {
    fun myPow(x: Double, n: Int): Double {
        if (x == 1.0) {
            return x
        } else if (x == -1.0) {
            when (Math.abs(n) % 2) {
                0 -> return -x
                1 -> return x
            }
        }
        
        var y = 1.0
        
        if (n > 0) {
            for (i in 1 .. n) {
                y *= x
                
                if (y == 0.0) {
                    return y
                }
            }
        } else if (n < 0) {
            for (i in -1 downTo n) {
                y /= x
                
                if (y == 0.0) {
                    return y
                }
            }
        }
        return y
    }
}