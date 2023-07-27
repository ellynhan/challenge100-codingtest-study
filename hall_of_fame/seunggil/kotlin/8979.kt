import java.io.*
import java.util.StringTokenizer
data class Country(val num : Int, val gold : Int, val sliver : Int, val bronze : Int, var rank : Int = 1)

fun main() = BufferedReader(InputStreamReader(System.`in`)).run{
    val (n, m) = readLine().split(" ").map { it.toInt() }

    val inputData = ArrayList<Country>(n)

    repeat(n){
        val token = StringTokenizer(readLine())
        inputData.add(Country(token.nextToken().toInt(), token.nextToken().toInt(), token.nextToken().toInt(), token.nextToken().toInt()))
    }
    val sortedInputData = inputData.sortedWith(compareByDescending<Country> {it.gold}.thenByDescending {it.sliver}.thenByDescending {it.bronze})

    var sameRank = 0

    if(sortedInputData[0].num == m){
        print(sortedInputData[0].rank)
        return@run
    }
    for(i in 1 until n){
        val before = sortedInputData[i-1]
        val now = sortedInputData[i]
        if(before.gold == now.gold && before.sliver == now.sliver && before.bronze == now.bronze){
            sameRank++
            now.rank = before.rank
        }else{
            now.rank = before.rank + sameRank + 1
            sameRank = 0
        }

        if(now.num == m){
            print(now.rank)
            break
        }
    }
}