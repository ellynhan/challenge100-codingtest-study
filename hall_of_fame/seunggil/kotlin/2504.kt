import java.io.*
import kotlin.collections.ArrayDeque
import kotlin.math.abs

var inputData : String = ""

fun calculate(start : Int, end : Int) : Int{
    if(start == end)
        return 1
    val stack = ArrayDeque<Char>()

    var ans = 0
    var start = start
    for(i in start until end){

        if(inputData[i] == '(' || inputData[i] == '[')
            stack.addLast(inputData[i]);
        else{
            // 괄호 모양 짝이 안맞을때
            if(stack.isEmpty() || abs(stack.last() - inputData[i]) > 2){
                return 0
            }else{
                stack.removeLast();
            }
        }

        if(stack.isEmpty()){
            ans += if(inputData[start]=='(') 2 * calculate(start+1,i) else 3 * calculate(start+1,i)
            start = i+1
        }
    }
    return if(stack.isEmpty()) ans else 0
}


fun main() = BufferedReader(InputStreamReader(System.`in`)).run{
    inputData = readLine()

    if(inputData.length % 2 == 1){
        print(0)
        return
    }

    var answer = calculate(0, inputData.length)

    print(answer)
}
