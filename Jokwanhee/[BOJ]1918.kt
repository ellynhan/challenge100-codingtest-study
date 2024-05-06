import java.util.Stack

fun main() {
    val inputs = readln().toList()

    val operator = Stack<Char>()
    for (i in inputs) {
        if (isAlphabet(i)) {
            print(i)
        } else {
            if (i == '(') {
                operator.add(i)
            } else if (isHighOperator(i)) {
                while (operator.isNotEmpty() && isHighOperator(operator.peek())) {
                    print(operator.pop())
                }
                operator.add(i)
            } else if (isLowOperator(i)) {
                while (operator.isNotEmpty() && operator.peek() != '(') {
                    print(operator.pop())
                }
                operator.add(i)
            } else if (i == ')') {
                while (operator.isNotEmpty() && operator.peek() != '(') {
                    print(operator.pop())
                }
                operator.pop()
            }
        }
    }

    while (operator.isNotEmpty()) {
        print(operator.pop())
    }
}

fun isAlphabet(alphabet: Char): Boolean =
    alphabet in 'A'..'Z'

fun isLowOperator(operator: Char): Boolean =
    operator == '+' || operator == '-'

fun isHighOperator(operator: Char): Boolean =
    operator == '*' || operator == '/'
