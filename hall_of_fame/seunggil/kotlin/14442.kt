import java.io.*
import java.util.*

class Pos(var x : Int, var y : Int, var length: Int = 1, var wall : Int = 0)

fun main() = with(BufferedReader(InputStreamReader(System.`in`))){

    val token = StringTokenizer(readLine())
    val n = token.nextToken().toInt()
    val m = token.nextToken().toInt()
    val k = token.nextToken().toInt()

    val inputData = Array(n) { CharArray(m) }

    val dx = intArrayOf(1,-1,0,0)
    val dy = intArrayOf(0,0,1,-1)

    for(i in 0 until n){
        val str = readLine()
        for(j in 0 until m){
            inputData[i][j] = str[j]
        }
    }

    val map = Array(n){ Array(m) { BooleanArray(k+1)} }
    val bfs = ArrayDeque<Pos>()
    bfs.addLast(Pos(0,0))
    map[0][0][0] = true
    while(bfs.isNotEmpty()){
        val now = bfs.poll()
        if(now.x == n-1 && now.y == m-1){
            print(now.length)
            return
        }
        for(dir in 0..3){
            val nextX = now.x + dx[dir]
            val nextY = now.y + dy[dir]

            if(nextX < 0 || nextX >= n || nextY < 0 || nextY >= m)
                continue

            if(inputData[nextX][nextY] == '1'){
                if(now.wall != k && !map[nextX][nextY][now.wall+1]){
                    map[nextX][nextY][now.wall+1] = true
                    bfs.add(Pos(nextX,nextY, now.length+1, now.wall+1))
                }
            }else if(!map[nextX][nextY][now.wall]){
                map[nextX][nextY][now.wall] = true
                bfs.add(Pos(nextX,nextY, now.length+1, now.wall))
            }
        }
    }

    print(-1)
}