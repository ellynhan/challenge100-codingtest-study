import kotlin.math.sqrt

class Solution {
    fun solution(k: Int, d: Int): Long {
        var answer = 0L
        for (i in 0..d step k) {
            val height = sqrt(((d + i).toLong() * (d - i).toLong()).toDouble()).toInt()
            answer += height / k + 1
        }
        return answer
    }
}