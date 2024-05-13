import java.util.LinkedList

fun main() {
    val edits = readln().toList()
    val lQ = LinkedList<Char>()
    edits.forEach {
        lQ.addLast(it)
    }
    val iterator = lQ.listIterator()
    while (iterator.hasNext()) iterator.next()

    repeat(readln().toInt()) {
        val input = readln().toList()
        when (input[0]) {
            'D' -> if (iterator.hasNext()) iterator.next()
            'L' -> if (iterator.hasPrevious()) iterator.previous()
            'B' -> if (iterator.hasPrevious()) {
                iterator.previous()
                iterator.remove()
            }

            'P' -> iterator.add(input[2])
        }
    }
    print(lQ.toCharArray())
}
