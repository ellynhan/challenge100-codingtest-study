import java.util.*
import java.io.*

val mod = 1000000007

fun pow(a : Long, p : Int) : Int{
    var a = a
    var p = p
    var result = 1
    while(p > 0){
        if(p % 2 == 1){
            result = ((result * a) % mod).toInt()
        }
        p = p.shr(1)
        a = (a * a) % mod

    }
    return result
}

fun main() = BufferedReader(InputStreamReader(System.`in`)).run {
    val token = StringTokenizer(readLine())
    val n = token.nextToken().toInt()
    val r = token.nextToken().toInt()

    val factorial = LongArray(n+1)
    factorial[0] = 1
    factorial[1] = 1

    for(i in 2..n){
        factorial[i] = (factorial[i-1].toLong() * i) % mod
    }

    var result = (factorial[n] * pow(factorial[n-r], mod-2)) % mod
    result = (result * pow(factorial[r], mod-2)) % mod

    print(result)
}