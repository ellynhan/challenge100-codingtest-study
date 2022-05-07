import java.io.*
import java.lang.StringBuilder

// [BOJ] 소음 / 브론즈3 / 20분
//https://www.acmicpc.net/problem/2935
fun main(args:Array<String>){
    val re = BufferedReader(InputStreamReader(System.`in`))
    var a : String = re.readLine()
    val operator : Char = re.readLine()[0]
    var b : String = re.readLine()

    val ans : java.lang.StringBuilder = StringBuilder()

    if(operator == '*'){
        val length = a.length + b.length - 2
        ans.append(1)
        for(i in 1..length){
            ans.append(0)
        }
    }else{
        if(a.length == b.length){
            ans.append(2)
            for(i in 2..a.length){
                ans.append(0)
            }
        }else{
            ans.append(1)

            if(a.length < b.length){
                val temp : String = a
                a = b
                b = temp
            }

            val length = a.length - b.length
            for(i in 2.. length){
                ans.append(0)
            }
            ans.append(1)
            for(i in 2..b.length)
                ans.append(0)
        }
    }
    println(ans)
    re.close()
}
