import java.util.*
import java.io.*

const val mod = 1000000000
fun main() {

    val re = Scanner(System.`in`)
    val n = re.nextInt()

    val dp = Array(n+1){ Array(10) { IntArray(1024)} }

    for(i in 1 .. 9){
        // 길이가 1이고 마지막 수가 i이고, 등장한 수는 bit인 수가 1개
        dp[1][i][1.shl(i)] = 1
    }

    for(len in 2 .. n){
        for(lastNum in 0 .. 9){
            if(lastNum-1 >= 0){
                val nowNum = lastNum - 1
                for(beforeStatus in 1 until 1024){
                    val nowStatus = beforeStatus.or(1.shl(nowNum))
                    dp[len][nowNum][nowStatus] += dp[len-1][lastNum][beforeStatus]
                    dp[len][nowNum][nowStatus] %= mod
                }
            }

            if(lastNum+1 <= 9){
                val nowNum = lastNum + 1
                for(beforeStatus in 1 until 1024){
                    val nowStatus = beforeStatus.or(1.shl(nowNum))
                    dp[len][nowNum][nowStatus] += dp[len-1][lastNum][beforeStatus]
                    dp[len][nowNum][nowStatus] %= mod
                }
            }
        }
    }

    var ans = 0L
    for(item in dp[n]){
        ans += item[1023]
        ans %= mod
    }
    print(ans)
    re.close()
}