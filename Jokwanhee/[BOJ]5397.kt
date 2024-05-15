import java.util.LinkedList

fun main() {
    repeat(readln().toInt()) {
        val input = readln().toList()
        val lQ = LinkedList<Char>()
        val iterator = lQ.listIterator()

        input.forEach {
            when (it) {
                '<' -> {
                    if (iterator.hasPrevious())
                        iterator.previous()
                }
                '>' -> {
                    if (iterator.hasNext())
                        iterator.next()
                }
                '-' -> {
                    if (iterator.hasPrevious()) {
                        iterator.previous()
                        iterator.remove()
                    }
                }
                else -> {
                    iterator.add(it)
                }
            }
        }

        println(lQ.toCharArray())
    }
}
