import java.io.*
import java.util.StringTokenizer

// [BOJ] 알람 시계 / 브론즈3 / 9분
// https://www.acmicpc.net/problem/2884
fun main(args: Array<String>) {
    val re = BufferedReader(InputStreamReader(System.`in`))
    val token = StringTokenizer(re.readLine());
    var hour = Integer.parseInt(token.nextToken())
    var min = Integer.parseInt(token.nextToken())

    min -= 45
    if(min < 0){
        min += 60
        hour -=1
    }

    hour = if(hour < 0) 24+hour else hour

    val ans = StringBuilder();
    ans.append(hour).append(' ').append(min)

    println(ans)
    re.close()
}