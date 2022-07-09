class Solution {
    fun solution(array: IntArray, commands: Array<IntArray>): IntArray {
        var answer = IntArray(commands.size)

        for(i in 0 until commands.size){
            var subArray = array.slice(commands[i][0]-1..commands[i][1]-1).sorted()
            answer.set(i, subArray[commands[i][2]-1])
        }
        return answer
    }
}