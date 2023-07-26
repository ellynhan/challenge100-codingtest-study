import java.io.BufferedReader
import java.io.InputStreamReader

// [BOJ] 구구단 / 브론즈3 / 10분
// https://www.acmicpc.net/problem/2739
fun main() {
    val re = BufferedReader(InputStreamReader(System.`in`))
    val n : Int = re.readLine().toInt()
    //val n : Int = Integer.parseInt(re.readLine())
    val ans : StringBuilder = StringBuilder()
    for(i in 1..9){
        ans.append("$n * $i = ${n*i}\n")
    }
    print(ans)
    re.close()
}