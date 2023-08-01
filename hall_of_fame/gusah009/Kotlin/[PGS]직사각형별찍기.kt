fun main(args: Array<String>) {
    val (n, m) = readLine()!!
        .split(' ')
        .map(String::toInt)
    for (i in 1..m) {
        for (j in 1..n) {
            print("*")
        }
        println()
    }
}