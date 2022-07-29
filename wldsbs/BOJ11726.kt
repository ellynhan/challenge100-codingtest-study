import java.util.*

fun main(){
    val sc: Scanner = Scanner(System.`in`)
    var n = sc.nextInt()
    
    var dp = IntArray(n + 1){
        if(it == 1) 1
        else if(it == 2) 2
        else -1
    }
    
    for(i in 3..n){
        dp[i] = (dp[i - 1] + dp[i - 2]) % 10007
    }
    println(dp[n])
}
