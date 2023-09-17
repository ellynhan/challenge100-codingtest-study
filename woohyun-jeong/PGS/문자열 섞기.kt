class Solution {
    fun solution(str1: String, str2: String): String {
        var answer: String = ""
        for (index in 0 until str1.length) {
            answer += str1[index]
            answer += str2[index]
        }
        return answer
    }
}