import java.util.Stack

class Solution {
    fun solution(n: Int): Int {
        var answer: Int = 0
        var input = n
        val queue = Stack<Int>()

        var base3 = 0
        while(input >= 3){
            queue.add(input % 3)
            input /= 3
        }
        queue.add(input % 3)

        var base = 1

        for(i in 0 until queue.size){
            answer += queue.pop() * base
            base *= 3
        }
        return answer
    }
}