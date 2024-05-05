import java.util.Stack

fun main() {
    val n = readln().toInt()
    val alphabets = arrayOf("A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z")
    val inputs = readln().toList().map { it.toString() }

    val numbers = DoubleArray(n)
    repeat(n) {
        numbers[it] = readln().toDouble()
    }

    val stack = Stack<Double>()
    var i = 0
    stack.add(numbers[alphabets.indexOf(inputs[i++])])
    while (stack.isNotEmpty()) {
        if (i >= inputs.size) break
        if (alphabets.contains(inputs[i])) {
            stack.add(numbers[alphabets.indexOf(inputs[i++])])
            continue
        }

        if (stack.size < 2) break
        val op = inputs[i++]
        val second = stack.pop()
        val first = stack.pop()
        stack.add(operator(first, second, op))
//        println("$first $op $second / ${stack.peek()}")
    }

    println(String.format("%.2f", stack.first()))
}

fun operator(a: Double, b: Double, op: String): Double =
    when (op) {
        "+" -> a + b
        "-" -> a - b
        "*" -> a * b
        "/" -> a / b
        else -> 0.0
    }
