import java.util.Stack

fun main() {
    val n = readln().toInt()

    val numbers = IntArray(n)
    repeat(n) {
        numbers[it] = readln().toInt()
    }

    val stack = Stack<Int>()
    val stackOp = Stack<String>()
    var i = 0
    var low = 1
    var high = numbers[i]
    for (number in low..numbers[i]) {
        stack.add(number)
        stackOp.add("+")
    }
    low = high
    var result = true

    while (stack.isNotEmpty()) {
        if (stack.peek() == high) {
            stack.pop()
            stackOp.add("-")
        } else {
            result = false
            break
        }
        if (i < n - 1) high = numbers[i + 1]
        if (low < high) {
            for (number in (low + 1)..high) {
                stack.add(number)
                stackOp.add("+")
            }
            low = high
        }
        i++
    }

    if (!result) {
        print("NO")
        return
    }
    stackOp.forEach {
        println(it)
    }
}
