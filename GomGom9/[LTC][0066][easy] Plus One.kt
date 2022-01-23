import java.math.BigInteger
import kotlin.time.ExperimentalTime
import kotlin.time.TimeSource

/**
topics : Array, Math
link : https://leetcode.com/problems/plus-one/submissions/
elapsed time : 5min
 */

/** My solutions */
class FirstSolution {
    fun plusOne(digits: IntArray): IntArray = digits.joinToString("")
        .toBigInteger()
        .plus(BigInteger.ONE)
        .toString()
        .toList()
        .map { Character.getNumericValue(it) }
        .toIntArray()
}

class Solution {
    fun plusOne(digits: IntArray): IntArray {
        var isNeedToPrepend: Boolean = false
        for (i in digits.lastIndex downTo 0) {
            if (digits[i] != 9) {
                digits[i]++
                break
            } else {
                if (i == 0) {
                    isNeedToPrepend = true
                }
                digits[i] = 0
            }
        }
        return if (isNeedToPrepend) intArrayOf(1, *digits) else digits
    }
}

/** Comments */

/** Other solutions */

/** Test cases */
@OptIn(ExperimentalTime::class)
fun main(args: Array<String>) {
    val solution = Solution()
    val startTimeMark = TimeSource.Monotonic.markNow()
    println(mutableListOf(1, 2, 3, 4, 5).subList(1, 3))
    val case1 = solution.plusOne(intArrayOf(7, 0, 1, 1, 1, 7, 4, 0, 0, 6))
    val case2 = solution.plusOne(intArrayOf(4, 3, 2, 1))
    val case3 = solution.plusOne(intArrayOf(9, 8, 7, 6, 5, 4, 3, 2, 1, 0))

    println("------------------------------")
    println(startTimeMark.elapsedNow())
    println("case1: ${case1.toReadableString()}")
    println("case2: ${case2.toReadableString()}")
    println("case3: ${case3.toReadableString()}")
    println("------------------------------")

}

private fun IntArray.toReadableString(): String = this.toList().toString()
private fun <T> Array<T>.toReadableString(): String = this.toList().toString()