import kotlin.time.ExperimentalTime
import kotlin.time.TimeSource

/**
topics : Math, Binary Search
link : https://leetcode.com/problems/sqrtx/
elapsed time : 19min
 */

/** My solutions */
class FirstSolution {
    fun mySqrt(x: Int): Int {
        var num = 0
        var squareNum = 0
        while (squareNum <= x) {
            if (x <= squareNum || squareNum < 0) {
                break
            } else {
                num++
                squareNum += (num * 2) + 1
            }
        }
        return num
    }
}

class Solution {
    private fun nextPow(num: Int, square: Int): Int = square + (num * 2) + 1

    private fun pow(num: Int): Int {
        var result = 0
        for (i in 0 until num) {
            result = nextPow(i, result)
        }
        return result
    }

    private fun recursionSqrt(startNum: Int, endNum: Int, target: Int): Int {
        val middleNum = (endNum - startNum) / 2 + startNum
        val square: Int = pow(middleNum)
        return when {
            square < target -> {
                val nextPow = nextPow(middleNum, square)
                if (nextPow > target || nextPow < 0) {
                    middleNum
                } else {
                    recursionSqrt(middleNum + 1, endNum, target)
                }
            }
            square == target -> middleNum
            else -> recursionSqrt(startNum, middleNum - 1, target)
        }
    }

    fun mySqrt(x: Int): Int {
        var dividedX = x
        var dividedCount = 0
        while (dividedX > 1) {
            dividedX /= 2
            dividedCount++
        }
        val startNum = if (dividedCount == 0) {
            0
        } else {
            var temp = 1
            for (i in 1..dividedCount / 2) {
                temp *= 2
            }
            temp
        }
        val endNum = Integer.min(startNum * 2, 46340)

        return recursionSqrt(startNum, endNum, x)
    }
}

/** Comments */
// Max value의 함정을 주의하자

/** Other solutions */
// Reference : https://leetcode.com/problems/sqrtx/discuss/25047/A-Binary-Search-Solution
//  -> 어차피 제곱인데 나는 왜 나눠서 비교할 생각을 못했지 ;;;;;...
fun sqrt(x: Int): Int {
    if (x == 0) return 0
    var left = 1
    var right = Int.MAX_VALUE
    while (true) {
        val mid = left + (right - left) / 2
        if (mid > x / mid) {
            right = mid - 1
        } else {
            if (mid + 1 > x / (mid + 1)) return mid
            left = mid + 1
        }
    }
}
/** Test cases */
@OptIn(ExperimentalTime::class)
fun main(args: Array<String>) {
    val solution = Solution()
    val startTimeMark = TimeSource.Monotonic.markNow()

    val case1 = solution.mySqrt(2147395600)
    val case2 = solution.mySqrt(2147483647)
//    val case3 = solution.mySqrt(4)

    println("------------------------------")
    println(startTimeMark.elapsedNow())
    println("case1: ${case1.toReadableString()}")
    println("case2: ${case2.toReadableString()}")
//    println("case3: ${case3.toReadableString()}")
    println("------------------------------")

}

private fun Int.toReadableString(): String = this.toString()
private fun IntArray.toReadableString(): String = this.toList().toString()
private fun <T> Array<T>.toReadableString(): String = this.toList().toString()