import java.util.ArrayDeque

fun main() {
    var n = readln().toInt()

    val cardSkills = readln().split(" ").map { it.toInt() }
    val result = ArrayDeque<Int>()

    n = 0
    for (c in cardSkills.size - 1 downTo 0) {
        n ++
        val top = cardSkills[c]
        when (top) {
            1 -> {
                result.addLast(n)
            }
            2 -> {
                val pop = result.pollLast()
                result.addLast(n)
                if (pop != null) {
                    result.addLast(pop)
                }
            }
            3 -> {
                result.addFirst(n)
            }
        }
    }

    print(result.reversed().joinToString(" "))
}
