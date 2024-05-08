fun main() {
    fun isValidation(x: Int, y: Int, nx: Int, ny: Int): Boolean =
        x in 0..(nx - 1) && y in 0..(ny - 1)

    fun isLand(item: Int): Boolean =
        item == 1

    fun dfs(g: MutableList<MutableList<Int>>, x: Int, y: Int, nx: Int, ny: Int): Boolean {
        if (!isValidation(x, y, nx, ny)) return false

        if (isLand(g[y][x])) {
            g[y][x] = 0

            dfs(g, x + 1, y, nx, ny) // 우
            dfs(g, x + 1, y + 1, nx, ny) // 우,아래
            dfs(g, x, y + 1, nx, ny) // 아래
            dfs(g, x - 1, y + 1, nx, ny) // 좌, 아래
            dfs(g, x - 1, y, nx, ny) // 좌
            dfs(g, x - 1, y - 1, nx, ny) // 좌, 위
            dfs(g, x, y - 1, nx, ny) // 위
            dfs(g, x + 1, y - 1, nx, ny) // 우, 위
            return true
        }
        return false
    }

    val resultCounts = mutableListOf<Int>()
    while (true) {
        val (x, y) = readln().split(" ").map { it.toInt() }
        if (x == 0 || y == 0) break
        val graph: MutableList<MutableList<Int>> = mutableListOf()
        repeat(y) {
            val numbers = readln().split(" ").map { it.toInt() }.toMutableList()
            graph.add(numbers)
        }

        var count = 0
        for (i in 0 until x) {
            for (j in 0 until y) {
                if (dfs(graph, i, j, x, y)) {
                    count++
                }
            }
        }

        resultCounts.add(count)
    }
    resultCounts.forEach {
        println(it)
    }
}
