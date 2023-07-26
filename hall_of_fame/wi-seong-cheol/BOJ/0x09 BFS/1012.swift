//
//  1012.swift
//  wi-seong-cheol
//
//  Created by wi_seong on 2022/12/14.
//

/*
 [Input]
 2
 10 8 17
 0 0
 1 0
 1 1
 4 2
 4 3
 4 5
 2 4
 3 4
 7 4
 8 4
 9 4
 7 5
 8 5
 9 5
 7 6
 8 6
 9 6
 10 10 1
 5 5
 [Output]
 5
 1
 */
// 시간복잡도: O(n * m)
// 최악시간: 2,500
// 난이도: Silver 2
// Timer: 15m
// Url: https://www.acmicpc.net/problem/1012

import Foundation

// 입력
let t = Int(readLine()!)!
var m, n, k: Int!

struct Coordinate {
    let x: Int
    let y: Int
}

let dx = [1, 0, -1, 0]
let dy = [0, 1, 0, -1]

// 풀이
for _ in 0 ..< t {
    solution()
}

func solution() {
    let mnk = readLine()!.split(separator: " ").map {Int(String($0))!}
    (m, n, k) = (mnk[0], mnk[1], mnk[2])
    var board = [[Int]](repeating: [Int](repeating: 0, count: m), count: n)
    for _ in 0 ..< k {
        let input = readLine()!.split(separator: " ").map {Int(String($0))!}
        let (x, y) = (input[0], input[1])
        board[y][x] = 1
    }
    
    var visited = [[Bool]](repeating: [Bool](repeating: false, count: m), count: n)
    
    func isVaildCoordinate(coord: Coordinate) -> Bool {
        return 0..<n ~= coord.y && 0..<m ~= coord.x
    }
    
    func dfs(coord: Coordinate) {
        visited[coord.y][coord.x] = true
        
        for i in 0..<4 {
            let nx = coord.x + dx[i]
            let ny = coord.y + dy[i]
            
            if(isVaildCoordinate(coord: Coordinate(x: nx, y: ny)) &&
               !visited[ny][nx] &&
               board[ny][nx] == 1) {
                visited[ny][nx] = true
                dfs(coord: Coordinate(x: nx, y: ny))
            }
        }
    }
    
    var ans = 0
    
    for y in 0..<n {
        for x in 0..<m {
            if !visited[y][x] && board[y][x] == 1 {
                ans += 1
                dfs(coord: Coordinate(x: x, y: y))
            }
        }
    }
    
    // 출력
    print(ans)
}
