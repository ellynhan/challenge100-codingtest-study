class Solution {
    fun solution(num: Int): Int {
        var answer = 0
        var input = num.toLong()
        while(input != 1.toLong()){
            if(input % 2 == 0.toLong()) {
                input /= 2
            } else{
                input = (input * 3) + 1
            }
            answer++
            println("$answer $input")
            if(answer > 500) return -1
        } 
        return answer
    }
}