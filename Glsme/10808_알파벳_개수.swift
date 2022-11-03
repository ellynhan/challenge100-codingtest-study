import Foundation
 
let line = readLine()!
var answer: [Int] = Array.init(repeating: 0, count: 26)

line.forEach {
    answer[Int($0.asciiValue!) - 97] += 1
}

print(answer.map { "\($0)" }.joined(separator: " "))
