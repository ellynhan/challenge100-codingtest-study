class Solution {
    fun solution(num_str: String): Int {
        var answer: Int = 0
        val numArray = num_str.toCharArray()
        for (char in numArray) {
            answer += char.toString().toInt()
        }
        return answer
    }
}